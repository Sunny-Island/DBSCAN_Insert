/*****************
April 12 2019
In Toronto
Created by Jiabei Zhao
*****************/
#include"Point.h"
Point::Point(int id, int* coords) {
	this->ID = id;
	this->coords = coords;
	this->isCore = false;
	//this->isProcessed = false;
	//this->isInQue = false;
	this->clusterID = -1;
}

void Point::reset() {
	this->isCore = false;
	//this->isProcessed = false;
	//this->isInQue = false;
	this->clusterID = -1;
}

void Point::assignToCluster(int clusterID)
{
	this->clusterID = clusterID;
}

double Point::getSqrDist(Point* pt)
{
	int dim = DIM;
	double sqr_dist = 0;
	double temp = 0;
	for (int i = 0; i < dim; i++) {
		temp = (this->coords[i] - pt->coords[i]);
		sqr_dist += temp * temp;
	}
	return sqr_dist;
}

double Point::getDist(Point* pt)
{
	return sqrt(this->getSqrDist(pt));
}

void Point::showCoords()
{
	int dim = DIM;
	printf("ID: %d\n", this->ID);
	printf("Point Coordinates: \n");
	for (int i = 0; i < dim; i++) 
	{
		printf("%d\t", this->coords[i]);
	}
	printf("\n");
}

vector<int>& Point::getGridCoords(vector<int>& gridCoords, double oneOverSideLen)
{
	int dim = DIM;
	int temp = 0;
	//floor function: return the first interger less than the argument
	for (int i = 0; i < dim; i++) 
	{
		temp = floor(this->coords[i] * oneOverSideLen);
		gridCoords.push_back(temp);
		/*push_back:add the argument into the vector, the location is the next of current
		location in vector
		*/

	}
	return gridCoords;
	// TODO: 在此处插入 return 语句
}


