/** Ramya Susarla
Material.h **/

#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
using namespace std; 
#include "Vector.h"
#include "Ray.h"


class Material{
public:
	Material();
	Material(Vector* c, double a, double d, double s, double r, bool check);
	Vector* colorAt(Vector* position);

	Vector* color; 
	double ambient, diffuse, specular, reflection;
	bool checkered;
};

#endif
