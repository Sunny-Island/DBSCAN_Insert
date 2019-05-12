#include "GridCell.h"

void GridCell::insertPointToCell(Point* pt)
{
	this->ptList.push_back(pt);
	this->size++;
}
