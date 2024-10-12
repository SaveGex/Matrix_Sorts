#include "pch.h"
#include "Matrix.h"
#include "Matrix.cpp"
TEST(ConstructorTests, InitTest) {
	Matrix obj1(1, 5);
	ASSERT_TRUE(obj1.matrix != nullptr); 
}

TEST(ConstructorTests, InitTest2) {
	Matrix obj1;
	int** mat = nullptr;
	ASSERT_EQ(obj1.matrix, mat, L"Not equal");
}

TEST(ConstructorTests, InitTest3) {
	int rows = 100;
	int cols = 1000;
	Matrix obj1(rows, cols);
	obj1.fulfill_random_fill(100, -100);
	for (int i = 0; i < rows; i++) {
		for (int a = 0; a < cols; a++) {
			ASSERT_FALSE(((obj1.matrix[i][a] > 100) || (obj1.matrix[i][a] < -100)), L"Not equal");
		}
	}
}




