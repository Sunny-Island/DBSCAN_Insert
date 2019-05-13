#include "GlobalVar.h"
#include<time.h>
void showError(string msg)
{
	printf("%s\n", msg.c_str());
	exit(0);
}

double getCurrentTime()
{
	long long int currenttime = chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now().time_since_epoch()).count();
	return  currenttime/1000000.0;//return in seconds

}

void computeLowestLevel()
{
	if (PHI > 0) {
		LOWEST_LEVEL = ceil(1 - log2(PHI));
		if (LOWEST_LEVEL < 1) {
			LOWEST_LEVEL = 1;
		}
	}
	else {
		LOWEST_LEVEL = 1;
	}
}

/*****************************************************************************
 *  The global variables.
 *****************************************************************************/

 /*
  *  The number of points.
  */
int N = -1;

/*
 *  The dimensionality of points.
 */
int DIM = 2;

/*
 *  The radius parameter for DBSCAN.
 */
double R = 1;

/*
 *  The core point threshold.
 */
int K = -1;

/*
 *  The approximation parameter for approximate DBSCAN.
 */
double PHI = -1;

/*
 *  The flag that whether to use the O(nk) algorithm for core point identification.
 *  If YES, this variable is TRUE. Otherwise, it is FALSE.
 */
bool USE_NK = true;

/*
 *  The flag that whether to use the space filling curve to get neighboring cells.
 *  If YES, this variable is TRUE. Otherwise, it is FALSE.
 */
bool USE_SPACE_FILLING = false;

/*
 *  The flag that whether to use the progressive method to construct grid graph.
 *  If YES, this variable is TRUE. Otherwise, it is FALSE.
 */
bool USE_PROGRESSIVE = false;

/*
 *  The flag that whether to use the space priority method to construct grid graph.
 *  If YES, this variable is TRUE. Otherwise, it is FALSE.
 */
bool USE_SPACE_PRIOR = false;

/*
 *  If a value is smaller than this threshold, then we regard this value is a constant.
 */
int CONSTANT_THRESHOLD = 100;

/*
*	Range of the coordinate in d-dimension
*/
int COOR_START = 0;
int COOR_END = 100;


/*
 *  All possible offsets for getting neighboring cells with non-negative coordinates.
 */
vector<vector<int>*> OFFSET_LIST;

/*
 *  The lowest level of the data structure which is used in approximate DBSCAN.
 */
int LOWEST_LEVEL = 1;

double TimeRtreeRangeQuery = 0;
double TimeCheckMbr = 0;
long long TotalRangeQueryNum = 0;
long long TotalOpenedMbrNum = 0;
long long TotalDistComputation = 0;
long long TotalStateCheck = 0;
