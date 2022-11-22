#include "Systems/PhysicRigidBody.h"

void PhysicRigidBody::update(float dt)
{
	_registry.updateForces();

	Coordinator* coordinator = Coordinator::getInstance();

	for (auto gameObject : entities_) {
		coordinator->getComponent<Rigidbody>(gameObject).Integrate(dt);
		coordinator->getComponent<Rigidbody>(gameObject).clearAccumulator();
	}
}