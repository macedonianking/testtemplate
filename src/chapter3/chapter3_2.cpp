#include "chapter3/chapter3_2.h"

#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

void chapter3_1_tutorial_problem() {
	string text;
	char ch;
	cin >> text;
	if (cin >> ch) {
		cout << (ch) << std::endl;
	}
}

void chapter3_5_exercise_a() {
	string line;
	while (getline(cin, line)) {
		cout << line << endl;
	}
}

void chapter3_5_exercise_b() {
	string word;
	while (cin >> word) {
		cout << word << endl;
	}
}

void chapter3_2_3_tutorial(const string &rhs) {
	string::size_type length = rhs.size();
	cout << "The size is " << length << endl;
	for (string::size_type i = 0; i < length; ++i) {
		cout << rhs[i] << endl;
	}
}
