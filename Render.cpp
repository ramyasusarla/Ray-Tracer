/** Ramya Susarla
Render.cpp

using namespace std;

#include <iostream>
#include <cmath>
#include <string>
#include "Ray.h"
#include "Vector.h"
#include "Render.h"



Vector*[][] Render:: render(Vector* cam, Sphere* b, Vector* col, int w, int h){
	double aspect_ratio = (double) w / h;
	double xmin = -1.0;
	double xmax =1.0;
	double delta_x = (xmax-xmin)/(w-1); // x step calculation ; max width is actually 319 , therefore minus 1
	double ymin = -1.0 / aspect_ratio;
	double ymax = 1.0 / aspect_ratio;
	double delta_y = (ymax-ymin)/(h-1);

	Vector* pixel[h][w]; 
	for(int r = 0; r<h; r++){
		double y = ymin + r*delta_y; 
		for(int c = 0; c<w; c++){
		 double x = xmin + c*delta_x; 
		 Vector* point = new Vector(x,y,0);
		 Ray* r = new Ray(c, point.subtract(c));
		 //NEED TO DO SMTH HERE
		 //pixel[r][c]  = HIS CODE: pixels.set_pixel(i, j, self.ray_trace(ray, cam, sphere, col, w, h))
		}
	}






	FILE *file = fopen("test.ppm", "w");
	fprintf(file, "P3\n %d %d\n%d\n", WIDTH, HEIGHT, 255);
	for(int r = 0; r<HEIGHT; r++){
		for (int c = 0; c<WIDTH; c++){
			checkVal(pixel[r][c]);
			fprintf(file, "%s",(pixel[r][c]->multiply(255)->toString() +" ").c_str()); 
		}
		fprintf(file, "\n");
	}

}*/

