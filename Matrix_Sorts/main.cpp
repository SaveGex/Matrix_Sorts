#include <iostream>
#include <gtest/gtest.h>
#include <stack>
#include <format>
#include <ctime>
#include "Matrix.h"
using namespace std;

void fill_data() {

}

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));

	Matrix obj1(5, 10);
	obj1.fulfill_random_fill(1, 10);
	Matrix obj2(5, 10);
	obj2.fulfill_random_fill(-1, -1);
	cout << obj1 << '\n' << obj2;
	Matrix addition = obj1 + obj2;
	cout << addition;


	Matrix subtraction = obj1-obj2;
	cout << subtraction;
	
	Matrix multiply = obj1 * obj2;
	cout << multiply;

	return 0;
}