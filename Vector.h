/** Ramya Susarla
Vector.h **/

#ifndef VECTOR_H
#define VECTOR_H

#include <string>
using namespace std; 

class Vector{
public:
	Vector();
	Vector(double a, double b, double c);

	Vector* normal();

	double magnitude();

	double dot(Vector* v);

	Vector* add(Vector* v);

	Vector* subtract(Vector* v);

	Vector* multiply (double a);

	Vector* divide (double a);

	string toString(); 

	double x, y, z; 

};

#endif

