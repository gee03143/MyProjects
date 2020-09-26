#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include "ShapeHeaders.h"

bool CirclevsCircle(Shape *lhs, Shape *rhs);
bool AabbvsAabb(Shape *lhs, Shape *rhs);
bool CirclevsAabb(Shape *c, Shape *a);
bool AabbvsCircle(Shape* c, Shape* a); // calls CirclevsAabb
bool TrianglevsTriangle(Shape* lhs, Shape* rhs);


#endif
