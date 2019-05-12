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
	/*
	for (int i = 0;i < firstSize;i++)
		for (int j = 0;j < firstSize;j++)
			for (int k = 0;k < firstSize;k++)
			{
				GridCell Child;
				Child.minValues[0] = i * FirstLen;
				Child.minValues[1] = j * FirstLen;
				Child.minValues[2] = k * FirstLen;
				//if()
				Child.maxValues[0] = (i + 1);

			}

	*/



	


	
	while (it != ptList.end())
	{
		//first chekc if the specific Grid exists
		//HashTable??......
		int* coords = (*it)->coords;


		it++;
	}
}
