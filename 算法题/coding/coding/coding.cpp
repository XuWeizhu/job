
#include <iostream>
#include "sort.h"

using namespace std;
int main()
{
	// sort
	if (sort::initialize("sort")) {
		sort::check(sort::select);
		sort::check(sort::shell);
		sort::check(sort::insert);//input pointer of function, here is select()
	}
	else {
		cout << "input wrong" << endl;
	}

	system("pause");
}
