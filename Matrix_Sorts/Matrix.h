#pragma once
#include <iostream>

class Matrix{
	int** matrix;
	int rows;
	int cols;

	void memory_allocation(int** matrix);
	void memory_allocation(int* matrix);
	bool is_sorted(int rows);
public:
	Matrix(const Matrix& obj);
	Matrix(Matrix&& obj) noexcept;
	Matrix(int** matrix, int rows, int cols);
	Matrix(int* array, int rows);
	Matrix(int rows, int cols);
	Matrix();
	~Matrix();

	Matrix operator+(const Matrix& obj);
	Matrix operator-(const Matrix& obj);
	Matrix operator*(const Matrix& obj);
	Matrix operator/(const Matrix& obj);

	friend std::ostream& operator<<(std::ostream& out, Matrix& obj);

	void fulfill_random_fill(int min_value, int max_value);
	int get_max();
	int get_min();

	#pragma region Sort_func
	int* quick_Sort(int* matrix, int max_index, int min_index);
	int** quick_Sort(int** matrix, int rows, int max_index, int min_index);
	void quick_Sort();
	#pragma endregion Sort_func


	friend class ConstructorTests_InitTest_Test;
	friend class ConstructorTests_InitTest2_Test;
	friend class ConstructorTests_InitTest3_Test;

};