/** Ramya Susarla
The Ray class holds specific information regarding the origin (ie. starting point of a ray) and the direction of the ray. This class is essential in 
properly replicating the direction and path of real life light rays.*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#include "Ray.h"
#include "Vector.h"


Ray::Ray(){
	origin = new Vector();
	dir = new Vector();
}

Ray::Ray(Vector* o, Vector* d){
	origin = o; 
	dir = d->normal(); 
}

