/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 32
 * Pointeurs de struct
 * https://www.youtube.com/watch?v=WmEncvVTOBg
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float x;
	float y;
} point;

void point_debug(point* p)
{
	printf("(%f; %f)", p->x, p->y);
}

void f(point* p)
{
	p->x +=3.6;
}

point point_creer(float x, float y)
{
	point p;
	p.x = x;
	p.y = y;

	return p;
}

point* point_creer_dyn(float x, float y)
{
	point* p = malloc(sizeof(point));
	p->x = x;
	p->y = y;

	return p;
}

int main(int argc, char* argv[])
{
	point p = point_creer(12.0, -3.0);

	point_debug(&p);
	printf("\n");

	p.x += 3.6;

	point_debug(&p);
	printf("\n");

	f(&p);

	point_debug(&p);
	printf("\n");

	return EXIT_SUCCESS;
}