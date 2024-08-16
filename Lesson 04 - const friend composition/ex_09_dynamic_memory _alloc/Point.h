#pragma once
//
// File: Point.h
// definition of class Point
// demonstration of dynamic memory allocation
//

class Point
{
public:
	Point(double x = 0, double y = 0);
	~Point();
	void setXY(double x, double y);
	void print() const;

private:
	double x;
	double y;
};
