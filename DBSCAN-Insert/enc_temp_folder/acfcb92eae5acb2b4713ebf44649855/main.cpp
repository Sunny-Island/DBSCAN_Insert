
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
	double A = 20;
	char B[10]="101";
	sprintf(B, "%d", A);
	char* a = &B[0];
	int i = 0;
	while (*a)
	{
		i++;
		cout << *a;
		a++;
	}

	cout << i;
	char C[10] = "101";


	return 0;

}