/*******************
May 12 2019
In Tsinghua
Created by Jiabei Zhao

********/

#include"ApproDBSCAN.h"
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 


void ApproDBSCAN::BulidGrid(vector<Point*> ptList)
{
	vector<Point*>::iterator it = ptList.begin();
	int RootLen = COOR_END - COOR_START;

	double FirstLen = R / sqrt(DIM);
	int firstSize = ceil(RootLen / FirstLen);
	//build first-level ceil
	this->root->ptList = ptList;
	for (int i = 0;i < DIM;i++)
	{
		this->root->minValues[i] = COOR_START;
		this->root->maxValues[i] = COOR_END;
	}
	this->root->ChildNumber = 0;
	this->root->isLeaf = false;

	for (int i = 0;i < firstSize;i++)
	{
		for (int j = 0;j < firstSize;j++)
		{
			GridCell* Child;
			Child->minValues[0] = i * FirstLen;
			Child->minValues[1] = j * FirstLen;

			if (i != firstSize - 1)
				Child->maxValues[0] = (i + 1) * FirstLen;
			else
				Child->maxValues[0] = COOR_END;

			if (j != firstSize - 1)
				Child->maxValues[1] = (j + 1) * FirstLen;
			else
				Child->maxValues[1] = COOR_END;
			
			FirstGridTable[i][j] = Child;

		}
	}
	
	while (it != ptList.end())
	{
		//first chekc if the specific Grid exists
		//HashTable??......
		int* coords = (*it)->coords;
		int i = floor(coords[0] / FirstLen);
		int j = floor(coords[1] / FirstLen);
		GridCell* TargetCell = this->FirstGridTable[i][j];
		double Len = FirstLen;
		int level = 0;
		TargetCell->level = ++level;
		TargetCell->sideLen = Len;
		double x = coords[0] - i * FirstLen;
		double y = coords[1] - j * FirstLen;
		TargetCell->ptList.push_back(*it);
		TargetCell->size++;
		while (Len > (R * PHI / sqrt(2)))
		{

			TargetCell->isLeaf = false;

			double coorx;
			double coory;


			if (x >= TargetCell->sideLen / 2 && y >= TargetCell->sideLen / 2)
			{
				x = x - TargetCell->sideLen / 2;
				y = y - TargetCell->sideLen / 2;
				coorx = TargetCell->sideLen / 2 + TargetCell->minValues[0];
				coory = TargetCell->sideLen / 2 + TargetCell->minValues[1];
				if (TargetCell->child4 == NULL)
				{
					TargetCell->child4 = new GridCell;
					TargetCell->child4->sideLen = TargetCell->sideLen / 2;
				}
				TargetCell = TargetCell->child4;
			}
			else if (x >= TargetCell->sideLen / 2 && y < TargetCell->sideLen / 2)
			{
				x = x - TargetCell->sideLen / 2;
				y = y;
				coorx  = TargetCell->sideLen / 2 + TargetCell->minValues[0];
				coory = TargetCell->minValues[1];
				if (TargetCell->child1 == NULL)
				{
					TargetCell->child1 = new GridCell;
					TargetCell->child1->sideLen = TargetCell->sideLen / 2;
				}
				TargetCell = TargetCell->child1;
			}
			else if (x < TargetCell->sideLen / 2 && y <= TargetCell->sideLen / 2)
			{	
				x = x;
				y = y;
				coorx = TargetCell->minValues[0];
				coory = TargetCell->minValues[1];
				if (TargetCell->child2 == NULL)
				{
					TargetCell->child2 = new GridCell;
					TargetCell->child2->sideLen = TargetCell->sideLen / 2;
				}
				TargetCell = TargetCell->child2;
			}
			else
			{
				x = x;
				y = y - TargetCell->sideLen / 2;
				coorx = TargetCell->minValues[0];
				coory = TargetCell->sideLen / 2 + TargetCell->minValues[1];
			}
		//此处省略3个if
		//已补充

			TargetCell->minValues[0] = coorx;
			TargetCell->minValues[1] = coory;
			TargetCell->maxValues[0] = coorx + TargetCell->sideLen;
			TargetCell->maxValues[1] = coory + TargetCell->sideLen;
			Len = TargetCell->sideLen;
			TargetCell->ptList.push_back(*it);
			TargetCell->size++;
			TargetCell->level = ++level;
		}
		TargetCell->isLeaf = true;


		it++;
	}
	//determain core points
}

int ApproDBSCAN::RangeQuery(Point* p)
{
	int ans = 0;
	double FirstLen = R / sqrt(DIM);
	int i = floor(p->coords[0] / FirstLen);
	int j = floor(p->coords[1] / FirstLen);

	//
	ans+=Query( p,  FirstGridTable[i][j]);
	return ans;
}

int ApproDBSCAN::Query(Point* p, GridCell* g)
{
	if (g == NULL)
		return 0;


	int cnt = 0;

	if (g->stateWithSphere(p, R) == -1)
		return 0;
	else if (g->stateWithSphere(p, R * (1 + PHI)) == 1)
		return g->size;
	else if(g->isLeaf = false)
	{
		cnt += Query(p, g->child1);
		cnt += Query(p, g->child2);
		cnt += Query(p, g->child3);
		cnt += Query(p, g->child4);
		return cnt;
	}
	else {
		if (g->stateWithSphere(p, R) == 0)
			return g->size;
	}
}

void ApproDBSCAN::DetermainCorePoints()
{
	int RootLen = COOR_END - COOR_START;

	double FirstLen = R / sqrt(DIM);
	int firstSize = ceil(RootLen / FirstLen);
	for (int i = 0;i < firstSize;i++)
	{
		for (int j = 0;j < firstSize;j++)
		{
			GridCell* g = FirstGridTable[i][j];
			vector<Point*> ptList = g->ptList;
			vector<Point*>::iterator it = ptList.begin();
			if (RangeQuery(*it) > K)
			{
				(*it)->isCore = true;
				g->coreNum++;
				g->isCore = true;
			}

		}
	}
}

bool ApproDBSCAN::EdgeAddable(GridCell* g1, GridCell* g2)
{
	int corenum1 = g1->coreNum;
	int coremum2 = g2->coreNum;
	if (corenum1 == 0 || coremum2 == 0)
	{
		return false;
	}
	if (coremum2 <= coremum1)//check every point in g2
	{

	}
	else
	{

	}
}
bool ApproDBSCAN::nonEmptinessOnCore(GridCell* g, Point* p)
{
	queue<GridCell*> queue;
	queue.push(g);
	int state = -1;
	int corenum = 0;
	GridCell* tempg = g;
	double Threshold = R * R * (1 + PHI) * (1 + PHI);
	while (!queue.empty)
	{
		tempg = queue.front();
		queue.pop();
		corenum = tempg->coreNum;
		if (corenum > 0)
		{
			state = g->stateWithSphere(p, R);
			if (state == 1)
			{
				return true;
			}
			else if (state == -1) {
				return false;
			}
			if (g->isLeaf) {
				vector<Point*> ptlist = g->ptList;
				int num = g->coreNum;
				for (int i = 0;i < num;i++)
				{
					if (p->getSqrDist(ptlist[i]) <= Threshold)
					{
						return true;
					}
				}
			}
			else {
				if (g->child1->coreNum != 0) {
					queue.push(g->child1);
				}
				if (g->child2->coreNum != 0) {
					queue.push(g->child2);
				}
				if (g->child3->coreNum != 0) {
					queue.push(g->child3);
				}
				if (g->child4->coreNum != 0) {
					queue.push(g->child4);
				}
			}
		}
		
	}


	return false;
}
void ApproDBSCAN::BuildEdge()
{
	int RootLen = COOR_END - COOR_START;

	double FirstLen = R / sqrt(DIM);
	int firstSize = ceil(RootLen / FirstLen);
	for ()
	{

	}
}






