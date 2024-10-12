#pragma once
#include <iostream>

class Matrix{
	int** matrix;
	int rows;
	int cols;

	void memory_allocation(int** matrix);
	void memory_allocation(int* matrix);
public:
	Matrix(const Matrix& obj);
	Matrix(Matrix&& obj);
	Matrix(int** matrix, int rows, int cols);
	Matrix(int* array, int rows);
	Matrix(int rows, int cols);
	Matrix();
	~Matrix();

	void fulfill_random_fill(int min_value, int max_value);

	Matrix operator+(const Matrix& obj);
	Matrix operator-(const Matrix& obj);
	Matrix operator*(const Matrix& obj);
	Matrix operator/(const Matrix& obj);
	friend std::ostream& operator<<(std::ostream& out, Matrix& obj);
	//friend std::ostream& operator<<(std::ostream& out, Matrix obj);


	friend class ConstructorTests_InitTest_Test;
	friend class ConstructorTests_InitTest2_Test;
	friend class ConstructorTests_InitTest3_Test;

};