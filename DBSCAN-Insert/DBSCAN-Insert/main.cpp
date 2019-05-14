/*
 * main.cpp
 *
 *  Created on: April 11, 2019
 *      Author: Jiabei Zhao
 *		In Toronto
 */



#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"headers.h"
#include<chrono>
#include"DataGenerator.h"
using namespace std;

int main()
{
	clock_t runTime;
	runTime = clock();


		
	runTime = clock() - runTime;

	printf("It took me %d clicks (%f seconds).\n", runTime, ((float)runTime) / CLOCKS_PER_SEC);


	char file[] = "jiabei_test";
	genDatasetToFile(file, DIM, 1000, 5, 10, COOR_START, COOR_END, 5);
	





	return 0;

}
