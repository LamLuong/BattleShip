#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__
#include <cmath>

class Point {
 public:
  Point(int x, int y) : x(x), y(y) {}


  Point operator+(const Point& v2) const {
    return Point(x + v2.x, y + v2.y);
  }

  Point operator*(int scalar) {
    return Point(x * scalar, y * scalar);
  }

  Point* operator*=(int scalar) {
    x *= scalar;
    y *= scalar;

    return this;
  }

  Point operator-(const Point& v2) const {
    return Point(x - v2.x, y - v2.y);
  }

  friend Point& operator-=(Point& v1, const Point& v2) {
    v1.x -= v2.x;
    v1.y -= v2.y;

    return v1;
  }

 public:
  int x;
  int y;

};
#endif
