#include <stdlib.h>
#include "Matrix.h"
#include <type_traits>

void Matrix::memory_allocation(int** matrix){

	this->matrix = new int* [cols];

	for (int i = 0; i < rows; i++) {
		this->matrix[i] = new int[rows];
		for (int a = 0; a < cols; a++) {
			this->matrix[i][a] = matrix[i][a];
		}
	}
}

void Matrix::memory_allocation(int* matrix){

	this->matrix = new int* [cols];

	for (int i = 0; i < rows; i++) {
		this->matrix[i] = new int[rows];
		for (int a = 0; a < cols; a++) {
			this->matrix[i][a] = matrix[a];
		}
	}
}

Matrix::Matrix(const Matrix& obj){
	this->rows = obj.rows;
	this->cols = obj.cols;
	this->matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols]();
	}
}

Matrix::Matrix(Matrix&& obj){
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
	/*(max_value < min_value) ? max_value = min_value : max_value = max_value;
	for (int i = 0; i < this->rows; i++) {
		for (int a = 0; a < this->cols; a++) {
			this->matrix[i][a] = min_value + rand() % (max_value - min_value + 1);
		}
	}*/
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
			buffer[i][j] = (buffer[i][j]) * (obj.matrix[i][j]);
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
//
//std::ostream& operator<<(std::ostream& out, Matrix obj){
//	for (int i = 0; i < obj.rows; i++) {
//
//		for (int a = 0; a < obj.cols; a++) {
//
//			out << obj.matrix[i][a] << ' ';
//		}
//
//		out << '\n';
//	}
//
//	return out;
//	
//}

