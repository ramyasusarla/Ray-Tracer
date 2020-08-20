/**
This file actually writes the .ppm file that can be run through a program such as GIMP to actually display image pixel by pixel. 
The program calculates the intersection of light rays based on light sources and objects present in the image to create a ray traced image with 
shading properties such as specular and diffuse lighting. 
**/
#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include<string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
#include "Vector.h"
#include "Sphere.h"
#include "Ray.h"
#include "Material.h"


void checkVal(Vector* v){
	if(v->x >1)
		v->x = 1;
	if(v->x < 0)
		v->x = 0; 
	if(v->y >1)
		v->y = 1;
	if(v->y < 0)
		v->y = 0; 
	if(v->z >1)
		v->z = 1;
	if(v->z < 0)
		v->z = 0; 
}

Vector* ray_trace(Ray* r, vector <Sphere*> objects, Vector* cam, vector <Vector*> lights, vector <Vector*> colors, int depth){
	Vector* color = new Vector();
	
	Sphere* obj_hit = NULL;
	double dist_min = 0.0;
	for(int i = 0; i< objects.size(); i++){
		double distance = objects[i]->intersect(r);
		if(distance >=.000000000000000000000000000000001 &&(obj_hit == NULL || distance<dist_min)){
			dist_min = distance;
			obj_hit = objects[i];
		}
	}
	
	if (obj_hit == NULL){
		return color;
	}
	Vector* hit_position = r->origin->add(r->dir->multiply(dist_min));
	Vector* hit_normal = obj_hit->norm(hit_position);

	//Calculating color at hit location
	Material* obj_material = obj_hit -> material;
	Vector* obj_color = obj_material -> colorAt(hit_position);
	Vector* dist_cam = cam->subtract(hit_position);
	color = obj_color->multiply(obj_material->ambient);
	int specularCoeff = 50;
	for(int k = 0; k<lights.size(); k++){

		Ray* lightSource = new Ray(hit_position, lights[k]->subtract(hit_position));

		//Diffuse shading formula 
		color = color->add(obj_color->multiply(obj_material->diffuse)->multiply(max(lightSource->dir->dot(hit_normal),0.0)));
		
		//Specular shading formula
		
		Vector* halfway = lightSource->dir->add(dist_cam)->normal();
		
		
		color = color->add(colors[k]->multiply(obj_material->specular)->multiply(pow(max(halfway->dot(hit_normal),0.0),specularCoeff)));
		
	}	
	if(depth< 5){
		Vector* new_position = hit_position->add(hit_normal->multiply(.0001));
		Vector* new_direction = r->dir->subtract(hit_normal->multiply(r->dir->dot(hit_normal)*2.0));
		Ray* new_ray = new Ray(new_position, new_direction);
		// adjust ray by reflection coefficient to account for dimness
		color = color->add(ray_trace(new_ray, objects, cam, lights, colors, depth+1)->multiply(obj_material->reflection));

	}

	return color;
}


int main(){
	int WIDTH = 960; 
	int HEIGHT = 540; 
	Vector* pixel[HEIGHT][WIDTH]; 

	//necessary rendering information
	Vector* camera = new Vector(0,-0.35,-1.5);
	Vector* light1 = new Vector (1.5, -.5, -10.0);
	Vector* light1Color = new Vector(1.0,1.0,1.0);
	Vector* light2 = new Vector (-0.5, -10.5, 0.0);
	Vector* light2Color = new Vector(230.0/255,230.0/255,230.0/255);
	
	//color of objects
	Vector* RED = new Vector(1,0,0);
	Vector* BLUE = new Vector(0,0,1);
	Vector* PINK = new Vector(50.0/255,22.0/255,50.0/255);
	Vector* BROWN = new Vector(165.0/255,42.0/255,42.0/255);
	Vector* GREEN = new Vector(0.0,1.00,0.0);

	//Objects in image
	Sphere* ball1 = new Sphere (new Vector(1.00,-0.1,2.00), .6, new Material(BLUE,.05,1.0,1.0,.5, false));
	Sphere* ball2 = new Sphere (new Vector(-1.00,-0.1,3.25), .6, new Material(PINK,.05,1.0,1.0,.5, false));
	Sphere* ball3 = new Sphere (new Vector(0.00,-.3,8.00), .6, new Material(GREEN,.05,1.0,1.0,.5, false));
	Sphere* ground = new Sphere (new Vector(0,10000.5,1.0), 10000.0, new Material(BROWN,.2,1.0,1.0,0.2,true));
	
	vector<Sphere*> objects;
	objects.push_back(ball1);
	objects.push_back(ball2);
	objects.push_back(ball3);
	objects.push_back(ground);
	vector<Vector*> lights;
	lights.push_back(light1);
	lights.push_back(light2);
	vector<Vector*> colors;
	colors.push_back(light1Color);
	colors.push_back(light2Color);
	
	

	double aspect_ratio = (double) WIDTH / HEIGHT;
	double xmin = -1.0;
	double xmax =1.0;
	double delta_x = (xmax-xmin)/(WIDTH-1); // x step calculation 
	double ymin = -1.0 / aspect_ratio;
	double ymax = 1.0 / aspect_ratio;
	double delta_y = (ymax-ymin)/(HEIGHT-1);


	for(int r = 0; r<HEIGHT; r++){
		double y = ymin + r*delta_y; 
		for(int c = 0; c<WIDTH; c++){
		 double x = xmin + c*delta_x; 
		 Vector* point = new Vector(x,y,0);
		 Ray* temp = new Ray(camera, point->subtract(camera));
		 //find nearest object hit by ray in scene
		 pixel[r][c] = ray_trace(temp, objects, camera, lights, colors,0);
		}
	}

	FILE *file = fopen("test.ppm", "w");
	fprintf(file, "P3\n %d %d\n%d\n", WIDTH, HEIGHT, 255);
	for(int r = 0; r<HEIGHT; r++){
		for (int c = 0; c<WIDTH; c++){
			checkVal(pixel[r][c]);
			pixel[r][c] = pixel[r][c]->multiply(255);
			pixel[r][c]->x = (int)pixel[r][c]->x;
			pixel[r][c]->y = (int)pixel[r][c]->y;
			pixel[r][c]->z = (int)pixel[r][c]->z;
			fprintf(file, "%s",(pixel[r][c]->toString() +" ").c_str()); 
		}
		fprintf(file, "\n");
	}
	return 0;
}