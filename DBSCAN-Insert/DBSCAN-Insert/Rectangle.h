/*
 * Rectangle.h
 *
 *  Created on: April 13, 2019
 *      Author: Jiabei Zhao
 *		In Toronto
 */
#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "headers.h"
#include "Point.h"

class Rectangle {
public:
	int* minValues;
	int* maxValues;//2 n-dimension point can define a n-dimensional rectangle
	Rectangle();
	Rectangle(int* minValues, int* maxValues);
	~Rectangle();

	bool intersect(const Rectangle& rec) const;
	bool inside(const Rectangle& rec) const;
	Rectangle& enlarge(const Rectangle& rec);
	//enlarge::find the minumum bounding of the two rectangle
	void setByRectangle(const Rectangle& rec);
	void setMinCoords(const int* minCoords);
	void setMaxCoords(const int* maxCoords);
	int stateWithSphere(Point* q, double r);
	/*stateWithSphere::
	*  return 1: fully inside
	*  return 0: intersect
	*  return -1:fully outside
	*
	*/

	void showRectangle();

};

#endif
