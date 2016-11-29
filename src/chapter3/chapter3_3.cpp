#include "chapter3/chapter3_3.h"

#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::string;

void chapter3_3_tutorial() {
	vector<int> list;
	for (int i = 0; i < 10; ++i) {
		list.push_back(i);
	}
	for (vector<int>::size_type i = 0; i < list.size(); ++i) {
		cout << list[i] << endl;
	}
}

void chapter3_14_problem() {
	vector<string> textList;
	string text;
	int n;

	while(cin >> text) {
		textList.push_back(text);
	}


	n = 0;
	for (vector<string>::size_type i = 0; i < textList.size(); ++i) {
		if (n != 0) {
			cout << " ";
		}
		cout << textList[i];
		if (++n == 8) {
			n = 0;
			cout << endl;		
		}
	}
}


