#include<stdio.h>
#include<math.h>

typedef struct vector{
  double x, y, z;
} Vector;

/**
 * Adds the vectors 'a' ad 'b' and pupulates the results
 * in vector res
 */
Vector* add(Vector *a, Vector *b){
  res = (Vector*)malloc(sizeof(Vector));
  res->x = a->x + b->x;
  res->y = a->y + b->y;
  res->z = a->z + b->z;
  return res;
}

double dot(Vector *a, Vector *b)
{
	return a->x*b->x + a->y*b->y + a->z*b->z;
}

Vector* cross(Vector *a, Vector *b)
{
  res = (Vector*)malloc(sizeof(Vector));
  res->x = a->y*b->z - a->z*b->y;
  res->y = a->z*b->x - a->x*b->z;
  res->z = a->x*b->y - a->y*b->x;
  return res;
}

/**
 * scale each entry of vector a by s. Note it
 * modifies the original vector.
 */
void scale(Vector *a, double s)
{
  a->x *= s;
  a->y *= s;
  a->z *= s;
}
