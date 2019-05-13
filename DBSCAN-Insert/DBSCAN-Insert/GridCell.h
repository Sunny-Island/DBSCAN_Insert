/*****************
April 28 2019
In Sky
Created by Jiabei Zhao
*****************/

#ifndef GRIDCELL_H_
#define GRIDCELL_H_


#include "Point.h"
#include"headers.h"
#include"Rectangle.h"
#include<set>

class GridCell:public Rectangle {
public:

	static GridCell* root;
	int ID;
	int size;
	int coreNum;
	vector<Point*> ptList;// the first coreNum points are key points
	int level;
	int sideLen;
	void insertPointToCell(Point* pt);
	bool isLeaf;
	bool isprocessed;
	vector<GridCell*> child;
	int ChildNumber;
	~GridCell();



};

#endif
