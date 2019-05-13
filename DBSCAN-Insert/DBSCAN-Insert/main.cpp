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

	cout << "hello world"<<endl;


	runTime = clock() - runTime;

	printf("It took me %d clicks (%f seconds).\n", runTime, ((float)runTime) / CLOCKS_PER_SEC);
	unsigned int a = 1;
	unsigned int b = 2;
	int c = 5 ^-1 ;
	cout << c << endl;
	int v1[] = { 1, 2, 3, 4, 5 };
	int v2[] = { 2,3,4,5,6 };
	vector<int> ates = { 1,2,3,4,5 };

	char file[] = "jiabei_test";
	//genDatasetToFile(file, DIM, 1000, 5, 10, COOR_START, COOR_END, 5);
	cout << floor(3 / 2.1);




	return 0;

}
