/*
 * headers.h
 *
 *  Created on: April 11, 2019
 *      Author: Jiabei Zhao
 *		In Toronto
 */
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include"headers.h"
#include<chrono>
using namespace std;


int main()
{
	clock_t runTime;
	runTime = clock();

	cout << "hello world"<<endl;

	double a = log2(5);




	runTime = clock() - runTime;
	double microseconds = chrono::duration
	printf("It took me %d clicks (%f seconds).\n", runTime, ((float)runTime) / CLOCKS_PER_SEC);



	return 0;

}