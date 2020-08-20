/** Ramya Susarla 
The Vector class is essential to represent the 3 dimensional space in which images are being created. 
Vector.cpp **/


#include <iostream>
#include <cmath>
#include <string>
#include "Vector.h"
using namespace std;
Vector::Vector(){
	x = 0;
	y = 0;
	z = 0;
}

Vector::Vector(double a, double b, double c){
	x = a;
	y = b;
	z = c;
}

Vector* Vector:: normal(){
	double mag = magnitude(); 
	Vector* a = new Vector();
	a -> x = x/mag;
	a -> y = y/mag;
	a -> z = z/mag;
	return a ;
}

double Vector:: magnitude(){
	return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}

double Vector:: dot(Vector* v){
	double dot = x * v->x + y * v->y  + z * v->z ;
	return dot;
}
Vector* Vector:: add(Vector* v){
	Vector* result = new Vector();
	result -> x = x + v-> x;
	result -> y = y + v-> y;
	result -> z = z + v-> z;

	return result;
}
Vector* Vector:: subtract(Vector* v){
	Vector* result = new Vector();
	result -> x = x - v-> x;
	result -> y = y - v-> y;
	result -> z = z - v-> z;

	return result;
}
Vector* Vector:: multiply(double a){
	Vector* result = new Vector();
	result -> x = x * a ;
	result -> y = y * a;
	result -> z = z * a;

	return result;
}
Vector* Vector:: divide(double a){

	if(a ==0 )
		return NULL;
	Vector* result = new Vector();
	result -> x = x / a ;
	result -> y = y / a;
	result -> z = z / a;

	return result;
}

string Vector:: toString(){
	string result = to_string(x) + " " + to_string(y)+ " "+ to_string(z); 
	return result;
}
