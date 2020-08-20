/** Ramya Susarla
This class is used to contain information regarding the objects rendered by the ray tracer. The sphere class also has the intersect method which returns the distance from Ray to Sphere and zero if no intersection occurs. 
In the main file to represent the flat ground, I am able to use an incredibly large Sphere radius and manipulate it's center to create the illusion of flatness. */
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
#include "Sphere.h"
#include "Vector.h"
#include "Ray.h"
#include "Material.h"


Sphere::Sphere(){
	center = NULL;
	radius = 0.0;
	material = NULL;
}

Sphere::Sphere(Vector* c, double r, Material* m){
	center = c;
	radius = r;
	material = m;
}

double Sphere:: intersect(Ray* r){
	Vector* sphere_to_ray = r -> origin-> subtract(center);
	double b = 2.0* r->dir->dot(sphere_to_ray); // b = 2* ray_direction * sphere_to_ray
	double c= sphere_to_ray->dot(sphere_to_ray) - radius*radius; // c= sphere_to_ray * sphere_to_ray - spherecenter^2
	double discriminant = b*b - 4.0*c; // a is assumed to be equal to 1

	if(discriminant >= 0 ){
		double d = (-b - sqrt(discriminant))/2.0;
		if(d>0.0)
			return d; 
	}
	else
		return 0.0;
}

Vector* Sphere:: norm(Vector* v){
	return v->subtract(center)->normal();
}


