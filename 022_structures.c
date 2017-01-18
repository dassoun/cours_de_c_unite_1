/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 22
 * Les structures (Les modules - partie 3)
 * https://www.youtube.com/watch?v=HhDtrHZmka8
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct _point point;

struct _point {
	float x;
	float y;
};

void point_debug(point p)
{
	printf("(%f; %f)", p.x, p.y);
}

point point_creer(float x, float y)
{
	point p;
	p.x = x;
	p.y = y;
	return p;
}

int main(int argc, char *argv[])
{
	point p = point_creer(3, 12);

	point_debug(p);
	printf("\n");

	p.y += 3.6;

	point_debug(p);
	printf("\n");

	return EXIT_SUCCESS;
}