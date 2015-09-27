//
//  mgoption.h
//  TouchVGCore
//
//  Created by Macbook on 8/17/15.
//  Copyright (c) 2015 rhcad. All rights reserved.
//

#ifndef TouchVGCore_mgoption_h
#define TouchVGCore_mgoption_h

// Option names

#define ZOOM_ENABLED        "zoomEnabled";
#define ZOOM_SNAP_ENABLED   "zoomSnapEnabled";
#define CONTEXT_ACTION_ENABLED   "contextActionEnabled";

#define SHOW_MAGNIFIER      "showMangnifier";
#define SHOW_GRID           "showGrid";
#define SHOW_ROTATE_TEXT    "showRotateText";

#define NEW_SHAPE_FIXED_LEN     "newShapeFixedlen";
#define NEW_SHAPE_FIXED_SIZE    "newShapeFixedsize";
#define NEW_SHAPE_LOCKED        "newShapeLocked";
#define NEW_SHAPE_HIDDEN        "newShapeHiden";

#define LOCK_SEL_SHAPE      "lockSelShape";
#define LOCK_SEL_HANDLE     "lockSelHandle";
#define LOCK_ROTATE_HANDLE  "lockRotateHandle";

#define SELECT_DRAW_FLAGS   "selectDrawFlags";
#define ROTATE_STEP_ANGLE   "rotateStepAngle";
#define DEGREE_DECIMAL      "degreeDecimal";
#define START_MUST_VERTEX   "startMustVertex";
#define DRAW_ONESHAPE       "drawOneShape";

#define PERP_OUT   "perpOut";
#define NOT_CLICK_SELECT_IN_DRAW_CMD   "notClickSelectInDrawCmd";

#define SNAP_ENABLED        "snapEnabled";
#define SNAP_VERTEX         "snapVertex";
#define SNAP_CENTER         "snapCenter";
#define SNAP_MID_POINT      "snapMidPoint";
#define SNAP_QUADRANT       "snapQuadrant";
#define SNAP_NEAR           "snapNear";
#define SNAP_EXTEND         "snapExtend";
#define SNAP_PERP           "snapPerp";
#define SNAP_TANGENT        "snapTangent";
#define SNAP_CROSS          "snapCross";
#define SNAP_PARALLEL       "snapParallel";
#define SNAP_GRID           "snapGrid";
#deifne SNAP_BG_GRID        "snapBgGrid";       // set true to snap to whole world grid cell vertex
#define SNAP_IN_GROUP       "snapInGroup";

#define SNAP_TEXT_ARGB      "snapTextARGB";     // snap text color

#define SNAP_ROUND_CELL     "snapRoundCell";    // snap point position rounding digitts

#define CAN_ROTATE_HANDLE   "canRotateHandle";
#define CAN_MOVE_SHAPE      "canMoveShape";
#define CAN_MOVE_HANDLE     "canMoveHandle";
#define CAN_BOX_SEL         "canBoxSel";




// Command names
#define CMD_DRAW_RECT       "rect";
#define CMD_DRAW_SQUARE     "square";
#define CMD_DRAW_ELLIPSE    "ellipse";
#define CMD_DRAW_CIRCLE     "circle2p";
#define CMD_DRAW_CIRCLE3P   "circle3p";
#define CMD_DRAW_DIAMOND    "diamond";
#define CMD_DRAW_LINE       "line";
#define CMD_DRAW_RAYLINE    "rayline";
#define CMD_DRAW_BEELINE    "beeline";
#define CMD_DRAW_FREELINES  "freelines";
#define CMD_DRAW_DOT        "dot";
#define CMD_DRAW_POLYLINE   "polygon";
#define CMD_DRAW_TRIANGLE   "triangle";
#define CMD_DRAW_GRID       "grid";
#define CMD_DRAW_LINES      "lines";
#define CMD_DRAW_SPLINES    "splines";
#define CMD_DRAW_QUADRANGLE   "quadrangle";
#define CMD_DRAW_SPLINEMOUSE   "spline_mouse";

#define CMD_ARC3P       "arc3p";
#define CMD_ARC_CSE     "arc_cse";
#define CMD_ARC_TAN     "arc_tan";
#define CMD_SECTOR      "sector";
#define CMD_PARALLEL    "parallel";

#define CMD_COMPASS     "compass";
#define CMD_ERASE       "erase";


enum MgShapeType {
    
    kMgShapes = 1,
    kMgLayoer = 7,
    
    kMgShape = 2,
    kMgShapeDoc = 8,

    kMgBaseShape    = 3,
    kMgArc          = 19,
    
    kMgbaseLines    = 5,
    kMgLines        = 15,
    kMgSplines      = 16,
    
    kMgBaseRect     = 4,
    kMgDiamond      = 14,
    kMgEllipse      = 12,
    kMgGrid         = 20,
    kMgImageShape   = 18,
    kMgRect         = 11,
    kMgRoundRect    = 13,
    
    kMgComposite    = 6,
    kMgGroup        = 9,
    
    kMgDot          = 31,
    kMgLine         = 10,
    kMgNote         = 35,
    kMgParallel     = 17,
    kMgPathShape    = 30,
    kMgRecordShape  = 32,

};

#endif
