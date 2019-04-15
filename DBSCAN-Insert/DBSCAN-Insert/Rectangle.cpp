/*
 * Rectangle.cpp
 *
 *  Created on: April 13, 2019
 *      Author: Jiabei Zhao
 *		In Toronto
 */
#include "Rectangle.h"

Rectangle::Rectangle()
{
	this->maxValues = new int[DIM];
	this->minValues = new int[DIM];
}

Rectangle::Rectangle(int* minValues, int* maxValues)
{
	this->minValues = minValues;
	this->maxValues = maxValues;
}

bool Rectangle::intersect(const Rectangle& rec) const
{
	for (int i = 0;i < DIM;i++) {
		if (this->minValues[i] > rec.maxValues[i]) {
			return false;
		}
		if (this->maxValues[i] < rec.minValues[i]) {
			return false;
		}
	}
	return true;
}

bool Rectangle::inside(const Rectangle& rec) const
{
	for (int i = 0; i < DIM; i++) {
		if (this->minValues[i] < rec.minValues[i]) {
			return false;
		}
		if (this->maxValues[i] > rec.maxValues[i]) {
			return false;
		}
	}
	return true;
}

Rectangle& Rectangle::enlarge(const Rectangle& rec)
{
	for (int i = 0; i < DIM; i++) {
		this->minValues[i] = min(this->minValues[i], rec.minValues[i]);
		this->maxValues[i] = max(this->maxValues[i], rec.maxValues[i]);
	}
	return *(this);
	//essentially, this function change current rectangle by merging

}

void Rectangle::setByRectangle(const Rectangle& rec)
{
	this->setMinCoords(rec.minValues);
	this->setMaxCoords(rec.maxValues);
}
void Rectangle::setMinCoords(const int* minCoords)
{
	if (this->minValues == NULL) {
		this->minValues = new int[DIM];
	}
	for (int i = 0; i < DIM; i++) {
		this->minValues[i] = minCoords[i];
	}
}

void Rectangle::setMaxCoords(const int* maxCoords)
{
	if (this->maxValues == NULL) {
		this->maxValues = new int[DIM];
	}
	for (int i = 0; i < DIM; i++) {
		this->maxValues[i] = maxCoords[i];
	}
}

int Rectangle::stateWithSphere(Point* q, double r)
{
	int dim = DIM;
	long long closestDist = 0;
	long long farthestDist = 0;
	long long temp = 0;
	long long temp2 = 0;
	long long sqr_temp = 0;
	long long sqr_temp2 = 0;
	double sqr_r = r * r;

	// Find the distances from the closest and farthest points to q in this grid cell.
	for (int i = 0; i < dim; i++) {
		temp = this->minValues[i] - q->coords[i];
		temp2 = this->maxValues[i] - q->coords[i];
		sqr_temp = temp * temp;
		sqr_temp2 = temp2 * temp2;

		if (temp > 0) {
			// q is to the left of this rectangle in this dimension
			closestDist += sqr_temp;
		}
		else if (temp2 < 0) {
			// q is to the right of this rectangle in this dimension
			closestDist += sqr_temp2;
		}
		farthestDist += (sqr_temp <= sqr_temp2 ? sqr_temp2 : sqr_temp);
	}

	if (closestDist <= sqr_r) {
		if (farthestDist <= sqr_r)
			return 1; // fully inside
		return 0; // intersect
	}
	return -1; // fully outside
}

void Rectangle::showRectangle()
{
	int dim = DIM;
	printf("The rectangle is bounded by: ");
	printf("(");
	for (int i = 0; i < dim - 1; i++) {
		printf("%d, ", this->minValues[i]);
	}
	printf("%d)\t", this->minValues[dim - 1]);

	printf("(");
	for (int i = 0; i < dim - 1; i++) {
		printf("%d, ", this->maxValues[i]);
	}
	printf("%d)\n", this->maxValues[dim - 1]);

}
