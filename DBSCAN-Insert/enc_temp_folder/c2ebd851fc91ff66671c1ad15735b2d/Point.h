/*****************
April 10 2019
In Toronto
Created by Jiabei Zhao
*****************/
#ifndef POINT_H_
#define POINT_H_
#include
class Point {
public:
	int ID;//point ID
	int* coords;// vector<int> coords
	int clusterID;//indicated the cluster the point belonged to
	bool isCore;//judge if the point is core point

	Point(int id, int* coords);//initialize the point
	void reset();//Reset the point to the initial state
	void assignToCluster(int clusterID);//ssign this point to a cluster.



};
#endif