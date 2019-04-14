
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include"headers.h"
using namespace std;
int main()
{
	clock_t runTime;
	runTime = clock();

	cout << "hello world"<<endl;






	runTime = clock() - runTime;
	printf("It took me %d clicks (%f seconds).\n", runTime, ((float)runTime) / CLOCKS_PER_SEC);



	return 0;

}