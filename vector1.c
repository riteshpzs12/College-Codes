#include<stdio.h>
#include<math.h>

typedef struct vector{
  double x, y, z;
} Vector;

/**
 * Adds the vectors 'a' ad 'b' and pupulates the results
 * in vector res
 */
void add(Vector *a, Vector *b, Vector *res){
  //if(res==NULL) {
    //res = (Vector*)malloc(sizeof(Vector));
  //}
  res->x = a->x + b->x;
  res->y = a->y + b->y;
  res->z = a->z + b->z;
}

void dot(Vector *a, Vector *b,double res)
{
	res = a->x*b->x + a->y*b->y + a->z*b->z;
}

void cross(Vector *a, Vector *b, Vector *res)
{
  	//if(res==NULL)
//	{
  //  	res = (Vector*)malloc(sizeof(Vector));
	//}
	res->x = a->y*b->z - a->z*b->y;
	res->y = a->z*b->x - a->x*b->z;
	res->z = a->x*b->y - a->y*b->x;
}

/**
 * scale each entry of vector a by s. Note it
 * modifies the original vector.
 */
void scale(Vector *a, double s)
{
	s = pow((a->x),2) + pow((a->y),2) + pow((a->z),2);
	s = pow((s),1/2);
}

