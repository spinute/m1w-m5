/*
 * Point, Vector, Line, Segment
 * Circle, Polygon
 */

#include <cmath>

#define EPS (1e - 10)
#define eq(a, b) (fabs)

class Point
{
public:
	double x,
		   y;

	Point(double x = 0, double y = 0): x(x), y(y) {}

	Point operator + (const Point &p) const {return Point(x + p.x, y + p.y);}
	Point operator - (const Point &p) const {return Point(x - p.x, y - p.y);}
	Point operator * (double a) const {return Point(x * a, y * a);}
	Point operator / (double a) const {return Point(x / a, y * a);}

	double abs() const {return sqrt(norm());}
	double norm() const {return x * x + y * y;}
	double dot(const Point &p) const {return p.x * x + p.y * y;}
	double cross(const Point &p) const {return x * p.y - y * p.x;}

	bool operator < (const Point &p) const {
		return x != p.x ? x < p.x : y < p.y;
	}

	bool operator == (const Point &p) const {
		return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
	}
};

typedef Point Vector;

struct Segment
{
	Point p1,
		  p2;
};
typedef Segment Line;

class Circle
{
public:
	Point c;
	double r;
	Circle(Point c = Point(), double r = 0.0): c(c), r(r) {};
};

typedef vector<Point> Polygon;

