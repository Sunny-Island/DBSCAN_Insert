/*
 * Hashing.h
 *
 *  Created on: April 15, 2019
 *      Author: Jiabei Zhao
 *		In Toronto
 */

#ifndef ZORDER_H_
#define ZORDER_H_

#include "headers.h"

typedef vector<unsigned int> Zorder;
static const int WORD = 32;
void encode(int* coords, Zorder& zdr, int bitNum = WORD);
bool compCode(const Zorder& z1, const Zorder& z2);
void showCode(Zorder& zdr, int dim, int bitNum = WORD);
bool compZorderByCoord(const int* v1, const int* v2);

bool compZorderByCoord(const vector<int>& v1, const vector<int>& v2);
#endif