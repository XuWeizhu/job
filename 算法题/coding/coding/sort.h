#pragma once

#include "core.h"
#include "inputHeader.h"

using namespace std;

typedef vector<int>(*pf)(vector<int>);
class sort
{
public:
	static vector< vector<int> > vecRandom;
	static vector< vector<int> > vecLabel;

	static bool initialize(string dir);
	static bool checkCore(vector<int> random, vector<int> label);
	static void check(pf p);

	static void exch(vector<int>& random, int index1, int index2);

	static vector<int> select(vector<int> nums);
	static vector<int> insert(vector<int> nums);
	static vector<int> shell(vector<int> nums);

	static vector<int> quick(vector<int> nums);

	
};

