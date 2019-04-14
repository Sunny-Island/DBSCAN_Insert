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
