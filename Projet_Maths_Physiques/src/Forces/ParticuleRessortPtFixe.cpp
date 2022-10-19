#include "Forces/ParticuleRessortPtFixe.h"

ParticuleRessortPtFixe::ParticuleRessortPtFixe(float kElasticite, Vecteur3D attache, Particule* particule) {
	_kElasticite = kElasticite;
	_attache = attache;
	_l0 = distance(particule->getPos, attache);
}

ParticuleRessortPtFixe::~ParticuleRessortPtFixe() {
	
}

virtual void ParticuleRessortPtFixe::updateForce(Particule* particule, float duration) {
	float l = distance(particule->getPos, _attache);
	particule->addForce(_kElasticite * (l - _l0));
};