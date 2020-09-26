#include "CollisionDetector.h"

#include <glm/glm.hpp>

bool CirclevsCircle(Shape* lhs, Shape* rhs) {
	Circle* L = reinterpret_cast<Circle*>(lhs);
	Circle* R = reinterpret_cast<Circle*>(rhs);

	float r = L->Radius + R->Radius;
	float dx = lhs->Position.x - rhs->Position.x;
	float dy = lhs->Position.y - rhs->Position.y;

	return r * r < dx* dx + dy * dy;
}

bool AabbvsAabb(Shape* lhs, Shape* rhs)
{
	Aabb* L = reinterpret_cast<Aabb*>(lhs);
	Aabb* R = reinterpret_cast<Aabb*>(rhs);

	if (L->Max().x < R->Min().x || L->Min().x > R->Max().x) return false;
	if (L->Max().y < R->Min().y || L->Min().y > R->Max().y) return false;

	return true;
}

bool CirclevsAabb(Shape* c, Shape* a)
{
	Circle* C = reinterpret_cast<Circle*>(c);
	Aabb* A = reinterpret_cast<Aabb*>(a);

	glm::vec2 deltaPos = c->Position - a->Position;
	glm::vec2 closestPoint = glm::clamp(a->Position + deltaPos, A->Min(), A->Max());

	float distance = glm::distance(closestPoint, c->Position);

	return distance < C->Radius;	//가장 가까운 점과의 거리가 반지름과의 거리보다 크다면 충돌한 것
}

bool AabbvsCircle(Shape* c, Shape* a) {
	return CirclevsAabb(a, c);
}

bool TrianglevsTriangle(Shape* lhs, Shape* rhs)
{
	//do something
	return false;
}
