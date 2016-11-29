#include "chapter3/chapter3_4.h"

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

void chapter3_4_tutorial() {
	vector<int> uniqueIdList;
	if (uniqueIdList.begin() == uniqueIdList.end()) {
		cout << "uniqueIdList is empty" << endl;
	}

	for (int i = 0; i < 10; ++i) {
		uniqueIdList.push_back(i);
	}
	for (vector<int>::iterator iter = uniqueIdList.begin();
		 iter != uniqueIdList.end();
		 ++iter) {
		*iter = 0;
	}
	for (vector<int>::const_iterator iter = uniqueIdList.begin();
		 iter != uniqueIdList.end();
		 ++iter) {
		cout << *iter << endl;
	}
}
