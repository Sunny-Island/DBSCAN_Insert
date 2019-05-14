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
	void assignCluster_DFS();//深搜，栈，搜到的点全部赋同一个值
	bool EdgeAddable(GridCell* g1, GridCell* g2);
	bool nonEmptinessOnCore(GridCell* g, Point* p);



};