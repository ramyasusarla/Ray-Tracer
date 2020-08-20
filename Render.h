/** Ramya Susarla
Render.h **/

#ifndef RENDER_H
#define RENDER_H

#include <string>
#include "Vector.h"
#include "Sphere.h"
#include "Ray.h"
using namespace std; 

class Render{
public:
	Render();
	

	Vector*[][] render(Vector* cam, Sphere* b, Vector* col, int w, int h);

};

#endif