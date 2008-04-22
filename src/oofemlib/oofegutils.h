#ifndef oofegutils_h
#define oofegutils_h

#ifdef __OOFEG
#include "oofeggraphiccontext.h"


void oofeg_drawIsoLinesOnTriangle(WCRec coords [ 3 ], double s [ 3 ]);
void oofeg_drawIsoLinesOnQuad(WCRec coords [ 4 ], double s [ 4 ]);

#endif
#endif // oofegutils_h
