#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct point
{
  int x;
  int y;
};

struct rectangle
{
  struct point p1;
  struct point p2;
};

double distance(struct point p1, struct point p2)
{
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double area(struct rectangle r)
{
  return abs(r.p1.x - r.p2.x) * abs(r.p1.y - r.p2.y);
}

int main()
{
  struct point pt1 = {10, 20};
  struct point pt2 = {30, 40};
  struct rectangle rect = {pt1, pt2};

  printf("dist : %lf \n", distance(pt1, pt2));
  printf("area : %lf \n", area(rect));

  return 0;
}

