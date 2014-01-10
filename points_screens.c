#include <stdio.h>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

struct point_ {
	int x;
	int y;
};
struct rect_ {
	struct point_ point1;
	struct point_ point2;
};


int main(int argc, char **argv)
{

struct point_ point;
struct point_ maxpoint={320,200};
struct rect_ screen;
struct point_ tmpoint;
struct rect_ tmprect;

	point.x=0;
	point.y=0;
	
	printf("px=%d, py=%d\n",point.x, point.y);
	printf("maxx=%d, maxy=%d\n",maxpoint.x, maxpoint.y);	
	
	
/*
 * Writing some functions to manipulate points and rectangles.
 * Three possible approaches: 
 * pass components separately, 
 * pass an entire structure, or 
 * pass a pointer to it. 
 * */
	
//	1.separately
struct point_ makePoint(int x, int y) {
	struct point_ temp;
	temp.x=x;
	temp.y=y;
	return temp;
}
	point=makePoint(4,5);
	printf("\n\nmakePoint\npx=%d, py=%d\n",point.x, point.y);
	
	
//  2.entire struct	
struct point_ addPoint(struct point_ point1, struct point_ point2) {
	point1.x += point2.x;
	point1.y += point2.y;
	return point1;
}
	tmpoint=makePoint(1,2);
	tmpoint=addPoint(tmpoint, point);
	printf("\n\naddPoint 1,2\npx=%d, py=%d\n",tmpoint.x, tmpoint.y);
	
	// check if point is in rectangle, return 1 if true, 0 if not
int pointInRect	(struct point_ point, struct rect_ screen){
	return point.x>=screen.point1.x && point.x<screen.point2.x \
			&& point.y>=screen.point1.y && point.y<screen.point2.y;
}
screen.point1=makePoint(0,0);
screen.point2=maxpoint;

	printf("\npointInRect\n");
	pointInRect(tmpoint, screen)?printf("point %d,%d is in screen", tmpoint.x, tmpoint.y):printf("OUT of SCREEN");
	
	// canonicalize coordinates of rectangle
struct rect_ canonRect(struct rect_ rect) {
	struct rect_ temp;
	temp.point1.x=min(rect.point1.x,rect.point2.x);
	temp.point2.x=max(rect.point1.x,rect.point2.x);
	temp.point1.y=min(rect.point1.y,rect.point2.y);
	temp.point2.y=max(rect.point1.y,rect.point2.y);
	return temp;
}

	tmprect.point1=makePoint(12,6);
	tmprect.point2=makePoint(8,2);
	
	printf("\n\ncanonRect, before canonicalization:\n");
	printf("p1.x=%d, p2.x=%d\n", tmprect.point1.x, tmprect.point2.x);
	printf("p1.y=%d, p2.y=%d\n", tmprect.point1.y, tmprect.point2.y);
	
	tmprect=canonRect(tmprect);
	printf("\ncanonRect, after canonicalization:\n");
	printf("p1.x=%d, p2.x=%d\n", tmprect.point1.x, tmprect.point2.x);
	printf("p1.y=%d, p2.y=%d\n", tmprect.point1.y, tmprect.point2.y);
	

//  3.a pointer to a struct	
struct point_ origin, *ppoint;

	origin=makePoint(7,77);
	ppoint=&origin;
	printf("\nOrigin is (%d,%d)", (*ppoint).x, (*ppoint).y);
	printf("\nOrigin is (%d,%d)", ppoint->x, ppoint->y);	// alternative notation
	
	

	return 0;
}







