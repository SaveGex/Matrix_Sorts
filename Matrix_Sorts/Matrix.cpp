#include <stdlib.h>
#include "Matrix.h"
#include <type_traits>
#include <algorithm>
void Matrix::memory_allocation(int** matrix){

	this->matrix = new int* [cols];

	for (int i = 0; i < rows; i++) {
		this->matrix[i] = new int[rows];
		for (int a = 0; a < cols; a++) {
			this->matrix[i][a] = matrix[i][a];
		}
	}
}

void Matrix::memory_allocation(int* array){

	this->matrix = new int* [cols];

	for (int i = 0; i < rows; i++) {
		this->matrix[i] = new int[rows];
		for (int a = 0; a < cols; a++) {
			this->matrix[i][a] = array[a];
		}
	}
}

bool Matrix::is_sorted(int rows){
	for (int j = 0; j < this->cols - 1; j++) {
		if (this->matrix[rows][j] > this->matrix[rows][j+1]) {
			return false;
		}
	}
	
	return true;
}

Matrix::Matrix(const Matrix& obj){
	this->rows = obj.rows;
	this->cols = obj.cols;
	this->matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols]();
	}
}

Matrix::Matrix(Matrix&& obj) noexcept{
	this->rows = obj.rows;
	this->cols = obj.rows;
	this->matrix = obj.matrix;
	obj.rows = 0;
	obj.cols = 0;
	obj.matrix = nullptr;	
}

Matrix::Matrix(int** matrix, int rows, int cols) : matrix{ matrix }, rows{ rows }, cols{ cols } 
{}

Matrix::Matrix(int* array, int rows) : rows{ rows }, cols{ 0 }, matrix { nullptr } {
	(rows > 0) ? cols = 1 : cols = 0;
	memory_allocation(array);
}

Matrix::Matrix(int rows, int cols) : rows{ rows }, cols{ cols }, matrix{ nullptr } {
	if (rows < 0) {
		this->rows = 0;
	}
	if (cols < 0) {
		this->cols = 0;
	}

	if (this->rows > 0 && this->cols > 0) {
		matrix = new int* [this->rows];
		for (int i = 0; i < this->rows; i++) {
			matrix[i] = new int[this->cols]();
		}
	}
}




Matrix::Matrix() : Matrix::Matrix(nullptr, 0, 0) {

}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Matrix::fulfill_random_fill(int min_value, int max_value) {

	if (max_value < min_value) {
		int buf = max_value;
		max_value = min_value;
		min_value = buf;
	}
	for (int i = 0; i < this->rows; i++) {
		for (int a = 0; a < this->cols; a++) {
			this->matrix[i][a] = min_value + rand() % (max_value - min_value + 1);
		}
	}
}

int partition(int* array, int min, int max) {
	int pivot = array[min];
	int i = min - 1, j = max + 1;
	
	while (true) {
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j) {
			return j;
		}
		std::swap(array[i], array[j]);

	}
}

int* Matrix::quick_Sort(int* array, int min_index, int max_index){
	for (int i = 0; i < rows; i++) {
		if (min_index < max_index) {
			int pi = partition(array, min_index, max_index);


			quick_Sort(array, pi, min_index);
			quick_Sort(array, max_index,pi + 1);
		}
	}
	return array;
}

int** Matrix::quick_Sort(int** matrix, int rows, int max_index, int min_index) {
	for (int i = 0; i < rows; i++) {
		quick_Sort(matrix[i], min_index, max_index - 1); 
	}
	return matrix;
}


void Matrix::quick_Sort(){

	for (int i = 0; i < this->rows; i++) {
		this->matrix[i] = quick_Sort(matrix[i], 0, this->cols - 1);
	}

}

Matrix Matrix::operator+(const Matrix& obj) {
	int rows = std::max(this->rows, obj.rows);  
	int cols = std::max(this->cols, obj.cols);  

	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++) {
		buffer[i] = new int[cols]();
	}

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			buffer[i][j] = this->matrix[i][j];
		}
	}

	for (int i = 0; i < obj.rows; i++) {
		for (int j = 0; j < obj.cols; j++) {
			buffer[i][j] += obj.matrix[i][j]; 
		}
	}

	return Matrix(buffer, rows, cols);
}


Matrix Matrix::operator-(const Matrix& obj){
	int rows = std::max(this->rows, obj.rows);
	int cols = std::max(this->cols, obj.cols);

	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++) {
		buffer[i] = new int[cols]();
	}

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			buffer[i][j] = this->matrix[i][j];
		}
	}

	for (int i = 0; i < obj.rows; i++) {
		for (int j = 0; j < obj.cols; j++) {
			buffer[i][j] = (buffer[i][j]) - (obj.matrix[i][j]);
		}
	}

	return Matrix(buffer, rows, cols);
}

Matrix Matrix::operator*(const Matrix& obj){
	int rows = std::max(this->rows, obj.rows);
	int cols = std::max(this->cols, obj.cols);

	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++) {
		buffer[i] = new int[cols]();
	}

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			buffer[i][j] = this->matrix[i][j];
		}
	}

	for (int i = 0; i < obj.rows; i++) {
		for (int j = 0; j < obj.cols; j++) {
			buffer[i][j] = (buffer[i][j]) * (obj.matrix[i][j]);
		}
	}

	return Matrix(buffer, rows, cols);
}

Matrix Matrix::operator/(const Matrix& obj) {
	int rows = std::max(this->rows, obj.rows);
	int cols = std::max(this->cols, obj.cols);

	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++) {
		buffer[i] = new int[cols]();
	}

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			buffer[i][j] = this->matrix[i][j];
		}
	}

	for (int i = 0; i < obj.rows; i++) {
		for (int j = 0; j < obj.cols; j++) {
			if (buffer[i][j] != 0 && obj.matrix[i][j] != 0) {
				buffer[i][j] = (buffer[i][j]) / (obj.matrix[i][j]);
			}
			else {
				buffer[i][j] = 0;
			}
		}
	}

	return Matrix(buffer, rows, cols);
}

std::ostream& operator<<(std::ostream& out, Matrix& obj){

	for (int i = 0; i < obj.rows; i++) {

		for (int a = 0; a < obj.cols; a++) {
			out << obj.matrix[i][a] << ' ';
		}

		out << '\n';
	}

	return out;
}