/*****************
April 19 2019
In Toronto
Created by Jiabei Zhao
*****************/

#include "DataGenerator.h"
#include"GlobalVar.h"
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979323846
double genUniformRandom(double rangeStart, double rangeEnd) {
	if (rangeStart > rangeEnd) {

		showError(
			"Error in genUniformRandom: the rangeEnd is < the rangeStart!\n");
	}
	double r;
	r = rangeStart
		+ ((rangeEnd - rangeStart) * (double)rand() / (double)RAND_MAX);
	if (r < rangeStart || r > rangeEnd) {
		showError(
			"Error in genUniformRandom: the number generated is not in the given range!\n");
	}
	return r;
}
double genGaussianRandom() {
	// Use Box-Muller transform to generate a point from normal
	// distribution.
	double x1, x2;
	do {
		x1 = genUniformRandom(0.0, 1.0);
	} while (x1 == 0); // cannot take log of 0.
	x2 = genUniformRandom(0.0, 1.0);
	double z;
	z = sqrt(-2.0 * log(x1)) * cos(2.0 * PI * x2);
	return z;
}
void genPtFromGaussian(vector<int>& center, double sigma, int dim,
	vector<int>& targetPlace) {
	targetPlace.clear();
	targetPlace.resize(dim, -1);
	double v = 0;

	for (int i = 0; i < dim; i++) {
		do {
			v = genGaussianRandom();
			v *= sigma;
			targetPlace[i] = center[i] + (int)(v + 0);
			if (targetPlace[i] > COOR_END)
				targetPlace[i] = COOR_END;
			if (targetPlace[i] < COOR_START)
				targetPlace[i] = COOR_START;
		} while (targetPlace[i] < 0);
	}
}
void genPtFromRandom(int dim, vector<int>& targetPlace, double rangeStart,
	double rangeEnd) {
	targetPlace.clear();
	targetPlace.resize(dim, -1);

	double v = 0;
	for (int i = 0; i < dim; i++) {
		v = genUniformRandom(rangeStart, rangeEnd);
		targetPlace[i] = (int)(v + 0);
		if (targetPlace[i] > rangeEnd) {
			targetPlace[i] = rangeEnd;
		}
	}
}
void writePointToFile(FILE* file, int id, vector<int>& coords) {
	if (file == NULL) {
		showError(
			"Error in function writePointToFile:\nThe file handler is NULL!\n");
	}
	fprintf(file, "%d", id);
	int dim = coords.size();
	for (int i = 0; i < dim; i++) {
		fprintf(file, "\t%d", coords[i]);
	}
	fprintf(file, "\n");

}
void genDatasetToFile(char* filePath, int dim, int totalNum, int clNum, int noiseNum,
	double rangeStart, double rangeEnd, double radius)
	{
		FILE* file = fopen(filePath, "wt");
		if (file == NULL) {
			showError(
				"Error in genDatasetToFile:\nFile open failed! Please check your file path!\n");
		}
		fprintf(file, "%d\t%d\n", totalNum, dim);
		vector<vector<int> > centerList;
		centerList.resize(clNum);
		for (int i = 0;i < clNum;i++)
		{
			genPtFromRandom(dim, centerList[i], rangeStart, rangeEnd);//generate center points
		}
		int avgNum = (totalNum - noiseNum) / clNum;
		int jumpNum = avgNum / 80;
		jumpNum = jumpNum ? jumpNum : 1;
		vector<int> targetPlace;
		int id = 1;
		for (int i = 0; i < clNum; i++) {
			for (int j = 0; j < avgNum; j++) {
				genPtFromGaussian(centerList[i], radius, dim, targetPlace);
				if (j > 0 && j % jumpNum == 0) {
					printf("%d pts generated.\n", j + i * avgNum);
					fflush(stdout);//flash cache,forced to output
				}
				writePointToFile(file, id, targetPlace);
				id++;
			}
		}
		noiseNum = totalNum - avgNum * clNum;
		for (int i = 0;i++;i < noiseNum)
		{
			genPtFromRandom(dim, targetPlace, rangeStart, rangeEnd);
			writePointToFile(file, id, targetPlace);
			id++;
		}
		fclose(file);

	}





