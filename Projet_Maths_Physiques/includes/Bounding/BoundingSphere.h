#pragma once
#ifndef BOUNDING_SPHERE_H
#define BOUNDING_SPHERE_H

#include "Bounding.h"

class BoundingSphere : public Bounding {
public:
	//Constructeur par d�faut
	BoundingSphere()=default;

	//Constructeur par valeurs
	BoundingSphere(const Vecteur3D& cent, float r) : Bounding(cent), radius(r) {};

	//Constructeur englobant 2 sph�res
	BoundingSphere(const BoundingSphere&, const BoundingSphere&);

	//Overlaps
	bool overlaps(const BoundingSphere& other) const;

	//Size
	float getSize() const override;

	//Growth
	float getGrowth(const BoundingSphere&) const;

	//Display
	std::string display() const;

	//Getter du rayon
	float getRadius() const { return radius; }

	//Op�rateur de pointeur
	//BoundingSphere* operator->() {
	//	return this;
	//}
protected:
	float radius;
};

#endif