/*****************
April 10 2019
In Toronto
Created by Jiabei Zhao
*****************/
#ifndef POINT_H_
#define POINT_H_
#include"headers.h"
class Point {
public:
	int ID;//point ID
	int* coords;// vector<int> coords
	int clusterID;//indicated the cluster the point belonged to
	bool isCore;//judge if the point is core point

	Point(int id, int* coords);//initialize the point
	void reset();//Reset the point to the initial state
	void assignToCluster(int clusterID);//assign this point to a cluster
	bool isProcessed;//if the point is under process
	bool isInQue;
	double getSqrDist(Point* pt);
	double getDist(Point* pt);
	void showCoords();
	vector<int>& getGridCoords(vector<int>& gridCoords, double oneOverSideLen);





};
#endif