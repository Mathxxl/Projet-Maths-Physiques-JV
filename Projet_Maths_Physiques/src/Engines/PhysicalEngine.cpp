#include "Engines/PhysicalEngine.h"
#include "Components/Transform.h"

PhysicalEngine::PhysicalEngine() : coordinator_(Coordinator::getInstance()), physicParticleSystem_(coordinator_->registerSystem<PhysicParticle>()), physicRigidBodySystem_(coordinator_->registerSystem<PhysicRigidBody>()), collisionsSystem_(coordinator_->registerSystem<CollisionsSystem>())
{
	coordinator_->registerComponent<Transform>();
	coordinator_->registerComponent<Particule>();
	coordinator_->registerComponent<Rigidbody>();
	coordinator_->registerComponent<std::shared_ptr<Collider>>();

	Signature physicParticleSignature;
	physicParticleSignature.set(coordinator_->getComponentType<Transform>());
	physicParticleSignature.set(coordinator_->getComponentType<Particule>());

	Signature physicRigidBodySignature;
	physicRigidBodySignature.set(coordinator_->getComponentType<Transform>());
	physicRigidBodySignature.set(coordinator_->getComponentType<Rigidbody>());

	Signature collisionsSignature;
	collisionsSignature.set(coordinator_->getComponentType<Transform>());
	collisionsSignature.set(coordinator_->getComponentType<std::shared_ptr<Collider>>());

	coordinator_->setSystemSignature<PhysicParticle>(physicParticleSignature);
	coordinator_->setSystemSignature<PhysicRigidBody>(physicRigidBodySignature);
	coordinator_->setSystemSignature<CollisionsSystem>(collisionsSignature);
}

void PhysicalEngine::update(float dt)
{
	physicParticleSystem_->update(dt);
	physicRigidBodySystem_->update(dt);
	collisionsSystem_->update(dt);
}