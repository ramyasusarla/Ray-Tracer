/** Ramya Susarla
Ray.h **/

#ifndef RAY_H
#define RAY_H

#include <string>
#include "Vector.h"
using namespace std; 

class Ray{
public:
	Ray();
	Ray(Vector* o, Vector* d);

	Vector* origin;
	Vector* dir; 

};

#endif
