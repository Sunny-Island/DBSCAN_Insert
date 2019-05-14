#include "GridCell.h"

void GridCell::insertPointToCell(Point* pt)
{
	this->ptList.push_back(pt);
	this->size++;
}

void GridCell::BuildEdge(GridCell* g)
{
	this->Edge.push_back(g);

}
