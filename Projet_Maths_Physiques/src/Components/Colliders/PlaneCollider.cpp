#include "Components/Colliders/PlaneCollider.h"

PlaneCollider::PlaneCollider(Entity entity, float halfSX, float halfSY, Vecteur3D n, Vecteur3D position, Vecteur3D orientation, Rigidbody* rigidbody) : Collider(entity, position, orientation, rigidbody), halfSizeX(halfSX), halfSizeY(halfSY), normal(n)
{
	type_ = PlanC;
}


float PlaneCollider::getMaxSize() const 
{
	if (halfSizeX > halfSizeY) return halfSizeX;
	return halfSizeY;
}