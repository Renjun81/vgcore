//! \file GcGraphView.cpp
//! \brief 实现主绘图视图类 GcGraphView
// Copyright (c) 2004-2015, https://github.com/rhcad/vgcore, BSD License

#include "GcGraphView.h"
#include "mglog.h"

// GcBaseView
//

GcBaseView::~GcBaseView()
{
    LOGD("View %p destroyed", this);
}

void GcBaseView::onSize(int dpi, int w, int h)
{
    xform()->setResolution((float)dpi);
    xform()->setWndSize(w, h);
}

bool GcBaseView::onGesture(const MgMotion& motion)
{
    if (motion.gestureType != kGiGesturePan || !_zoomEnabled){
        return false;
    }
    if (motion.gestureState <= kMgGestureBegan) {
        _lastScale = xform()->getZoomValue(_lastCenter);
    }
    else if (motion.gestureState == kMgGestureMoved) {
        Vector2d vec(motion.point - motion.startPt);
        xform()->zoom(_lastCenter, _lastScale);     // 先恢复
        xform()->zoomPan(vec.x, vec.y);             // 平移到当前点
        _zooming = true;
        cmdView()->regenAll(false);
    }
    else if (_zooming) {
        _zooming = false;
        cmdView()->regenAll(false);
    }
    
    return true;
}


bool GcBaseView::twoFingersMove(const MgMotion& motion)
{
    if (!_zoomEnabled) {
        return false;
    }
    if (motion.gestureState <= kMgGestureBegan) {
        _lastScale = xform()->getZoomValue(_lastCenter);
    }
    else if (motion.gestureState == kMgGestureMoved
        && motion.startPt != motion.startPt2
        && motion.point != motion.point2) {         // 双指变单指则忽略移动
        Point2d at((motion.startPt + motion.startPt2) / 2);
        Point2d pt((motion.point + motion.point2) / 2);
        float d1 = motion.point.distanceTo(motion.point2);
        float d0 = motion.startPt.distanceTo(motion.startPt2);
        float scale = d1 / d0;
        
        xform()->zoom(_lastCenter, _lastScale);     // 先恢复
        xform()->zoomByFactor(scale - 1, &at);      // 以起始点为中心放缩显示
        xform()->zoomPan(pt.x - at.x, pt.y - at.y); // 平移到当前点
        
        _zooming = true;
        cmdView()->regenAll(false);
    }
    else if (_zooming) {
        _zooming = false;
        cmdView()->regenAll(false);
    }
    
    return true;
}


void GcBaseView::draw(GiGraphics&)
{
}

void GcBaseView::dyndraw(GiGraphics&)
{
}

// GcGraphView
//

GcGraphView::GcGraphView(MgView* mgview, GiView *view) : GcBaseView(mgview, view)
{
}

GcGraphView::~GcGraphView()
{
}

void GcGraphView::draw(GiGraphics& gs)
{
    const char* bgImage = cmdView()->getOptionString("backgroundImage");
    if ( strlen(bgImage) > 0 )
    {
        float width = cmdView()->getOptionFloat("backgroundWidth", 0.f);
        float height = cmdView()->getOptionFloat("backgroundHeight", 0.f);
        if ( width > 0 && height > 0 )
        {
            Box2d bgRect(Point2d::kOrigin(), width, height);
            bgRect *= gs.xf().displayToModel();
            bgRect *= gs.xf().getViewScale();
            gs.drawImage(bgImage, Point2d::kOrigin(), bgRect.width(), bgRect.height());
        }
    }
    
    int gridType = cmdView()->getOptionInt("showGrid", 0);
    if (gridType < 1 || gridType > 2 || gs.xf().getViewScale() < 0.05f)
        return;
    
    
    int nStrongGap = 1;
    float gridSize = cmdView()->getOptionFloat("gridSize", 10.f);
    
    Box2d rect(gs.xf().getWndRectW());
    
    int nColor = cmdView()->getOptionInt("gridColor", 0);
    
    GiColor colorNormal;
    GiColor colorLight;
    if ( nColor == 0 )
    {
        colorNormal.set(127, 127, 127, 48);
        colorLight.set(127, 127, 127, 24);
    }
    else
    {
        if ( (nColor >> 24) > 0 )
            colorNormal.setARGB(nColor);
        else
        {
            colorNormal.setARGB(nColor);
            colorNormal.a = 255;
        }
        colorLight = colorNormal;
        colorLight.a /= 2;
    }
    
    //float x = mgbase::roundReal(rect.xmin, -1) - 10;
    //float y = mgbase::roundReal(rect.ymin, -1) - 10;
    float x = gridSize * mgRound(rect.xmin / gridSize);
    float y = gridSize * mgRound(rect.ymin / gridSize);
    
    if (gridType == 1)
    {
        GiContext ctx(0, colorLight);
        GiContext ctx5(0, colorNormal);
        
        int i = (int)(x/gridSize); // mgRound(x) / 10;
        for (; x < rect.xmax + gridSize; x += gridSize) {
            gs.drawLine(i++ % nStrongGap ? &ctx : &ctx5, Point2d(x, rect.ymin), Point2d(x, rect.ymax), false);
        }
        
        i = (int)(y/gridSize); //mgRound(y) / 10;
        for (; y < rect.ymax + gridSize; y += gridSize) {
            gs.drawLine(i++ % nStrongGap ? &ctx : &ctx5, Point2d(rect.xmin, y), Point2d(rect.xmax, y), false);
        }
    }
    else if (gridType == 2)
    {
        GiContext ctx(0, colorNormal);
        for (; x < rect.xmax + gridSize; x += gridSize) {
            for (; y < rect.ymax + gridSize; y += gridSize) {
                gs.drawLine(&ctx, Point2d(x, y - 0.5f), Point2d(x, y + 0.5f), false);
                gs.drawLine(&ctx, Point2d(x - 0.5f, y), Point2d(x + 0.5f, y), false);
            }
        }
    }
    
    //// draw axis and original point
    //gs.drawLine(Pont2d(0, rect.ymin), Point2d(0, rect.ymax));
    //gs.drawLine(Point2d(rect.xmin, 0), Point2d(rect.xmax, 0));
    //gs.drawCircle(&ctx, Point2d::kOrigin(), 1);
    
    GcBaseView::draw(gs);
}
