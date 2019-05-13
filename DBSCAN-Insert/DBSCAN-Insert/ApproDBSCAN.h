/*******************
May 12 2019
In Tsinghua
Created by Jiabei Zhao

********/

#include "GridCell.h"

#include "headers.h"
class ApproDBSCAN {
	GridCell* root;
	GridCell** FirstGridTable[];

	void BulidGrid(vector<Point*> ptList);
	int RangeQuery(Point* p);
	int Query(Point* p, GridCell* g);
	void DetermainCorePoints();
	void BuildEdge();
	void assignCluster();



};