/** Ramya Susarla
This class is used to hold information regarding the material of the objects in the ray-traced image. This information, specifically color, ambient, diffuse, 
specular, and reflection, allow for more realistic rendering of images and can be manipulated to create, for example, more reflective shinier objects or duller objects.
Material.cpp **/
#include <iostream>

using namespace std;
#include "Vector.h"
#include "Ray.h"
#include "Material.h"


Material::Material(){
	color = new Vector(1.0,1.0,1.0);
	ambient = .05;
	diffuse = 1.0 ;
	specular = 1.0;
	reflection = .5;
	checkered = false;
}

Material::Material(Vector* c, double a, double d, double s, double r, bool check){
	color = c;
	ambient = a;
	diffuse = d ;
	specular = s;
	reflection = r;
	checkered = check;
}

Vector* Material:: colorAt(Vector* position){
	//if not checkered sphere then  return main solid color
	if(!checkered){
		return color;
	}
	else{
		//two main checker board colors
		Vector* black = new Vector(0.0,0.0,0.0); 
		Vector* white = new Vector(1.0,1.0,1.0);
		if(int((position->x +5.0)*3.0)%2 == int(position->z*3.0)%2)
			return black;
		else
			return white;
	}

}