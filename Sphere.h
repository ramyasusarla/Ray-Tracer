/** Ramya Susarla
Sphere.h **/

#ifndef SPHERE_H
#define SPHERE_H

#include <string>
using namespace std; 
#include "Vector.h"
#include "Ray.h"
#include "Material.h"


class Sphere{
public:
	Sphere();
	Sphere(Vector* c, double r, Material* m);

	double intersect(Ray* r);
	Vector* norm(Vector* v);
	Vector* colorAt(Vector* position);

	double radius; 
	Vector* center; 
	Material* material; 

};

#endif

