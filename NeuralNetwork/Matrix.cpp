#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <vector>
#include <iomanip>

#define MATRIX_MAX_SIZE 1024


using namespace std;


template<class T>
inline Matrix<T>::Matrix(size_t rows, size_t cols)
{
	//cout << "rows: " << rows << "columns: " << cols << endl;
	if (rows == 0 || cols == 0 || rows > MATRIX_MAX_SIZE || cols > MATRIX_MAX_SIZE)
	{ 
		cout << "Nonpositive amount of rows or/and columns" << endl;
		exit(0);
	}
	else {
		this->rows = rows;
		this->cols = cols;
		data = vector<T>(rows*cols, 0);
	}
}

template<class T>
inline Matrix<T>::Matrix(size_t rows, size_t cols, std::vector<T> data)
{
	if (data.size() != rows * cols) {
		cout << "rows*cols != data.size()" << endl;
		exit(0);
	}
	if (rows == 0 || cols == 0 || rows > MATRIX_MAX_SIZE || cols > MATRIX_MAX_SIZE) {
		cout << "\"rows\" and \"cols\" must be more than 0" << endl;
		exit(0);
	}
	this->rows = rows;
	this->cols = cols;
	this->data = data;
}

template<class T>
inline Matrix<T>::~Matrix()
{
	vector<T>().swap(data);
}

template<class T>
size_t Matrix<T>::getRows()
{
	return this->rows;
}

template<class T>
size_t Matrix<T>::getCols()
{
	return this->cols;
}

template<class T>
inline T & Matrix<T>::operator()(size_t i, size_t j)
{
	if (i >= 0 && i < this->rows && j >= 0 && j < this->cols) {
		return data.at(i*this->cols + j);
	}
	else {
		cout << "Out of bounds " << this->rows << " " << this->cols <<endl;
		cout << "i " << i << ", j " << j << endl;
		exit(0);
	}
}

template<class T>
inline T Matrix<T>::operator()(size_t i, size_t j) const
{
	if (i >= 0 && i < rows && j >= 0 && j < cols) {
		return data.at(i*cols + j);
	}
	else {
		cout << "Out of bounds(2) " << endl;
		exit(0);
	}
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T> m)
{
	if (m.rows == this->rows && m.cols == this->cols) {
		this->rows = m.rows;
		this->cols = m.cols;
		this->data = m.data;
		return *this;
	}
	cout << "Matrices of different size(1)" << endl;
	exit(0);
}

template<class T>
Matrix<T> Matrix<T>::operator=(Matrix<T> m) const
{
	if (m.rows == this->rows && m.cols == this->cols) {
		this->rows = m.rows;
		this->cols = m.cols;
		this->data = m.data;
		return *this;
	}
	cout << "Matrices of different size(2)" << endl;
	exit(0);
}

template<class T>
Matrix<T>& Matrix<T>::operator+=(Matrix<T> m)
{
	if (m.rows == this->rows && m.cols == this->cols)
	{
		for (int i = 0; i < m.rows; i++)
			for (int j = 0; j < m.cols; j++)
				(*this)(i, j) = (*this)(i, j) + m(i, j);
		//m3.print();
		return *this;
	}
	cout << "Can't add different matricies(5)" << endl;
	exit(0);
}

template<class T>
Matrix<T> Matrix<T>::operator+=(Matrix<T> m) const
{
	if (m.rows == this->rows && m.cols == this->cols)
	{
		for (int i = 0; i < m.rows; i++)
			for (int j = 0; j < m.cols; j++)
				this(i, j) = this(i, j) + m(i, j);
		//m3.print();
		return this;
	}
	cout << "Can't add different matricies(4)" << endl;
	exit(0);
}

template<class T>
Matrix<T>& Matrix<T>::operator+(Matrix<T> m)
{
	if (m.rows == this->rows && m.cols == this->cols) 
	{
		return (*this) += m;
	}
	cout << "m.rows " << m.rows << ", m.cols " << m.cols << endl;
	cout << "this->rows " << this->rows << ", this->cols " << this->cols << endl;
	cout << "Can't add different matricies(6)" << endl;
	exit(0); 
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> m) const
{
	if (m.rows == this->rows && m.cols == this->cols) 
	{
		return (*this) += m;
	}
	cout << "m.rows " << m.rows << ", m.cols " << m.cols << endl;
	cout << "this->rows " << this->rows << ", this->cols " << this->cols << endl;
	cout << "Can't add different matricies(7)" << endl;
	exit(0); 
}

template<class T>
Matrix<T>& Matrix<T>::operator-=(Matrix<T> m)
{
	if (m.rows == this->rows && m.cols == this->cols)
	{
		for (int i = 0; i < m.rows; i++)
			for (int j = 0; j < m.cols; j++)
				(*this)(i, j) = (*this)(i, j) - m(i, j);
		return *this;
	}
	cout << "Can't subtract different matricies(1)" << endl;
	exit(0);
}

template<class T>
Matrix<T> Matrix<T>::operator-=(Matrix<T> m) const
{
	if (m.rows == this->rows && m.cols == this->cols)
	{
		for (int i = 0; i < m.rows; i++)
			for (int j = 0; j < m.cols; j++)
				(*this)(i, j) = (*this)(i, j) - m(i, j);
		return *this;
	}
	cout << "Can't subtract different matricies(1)" << endl;
	exit(0);
}

template<class T>
Matrix<T>& Matrix<T>::operator-(Matrix<T> m)
{
	if (m.rows == this->rows && m.cols == this->cols)
	{
		return (*this) -= m;
	}
	cout << "Can't subtract different matrices(3)" << endl;
	exit(0);
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> m) const
{
	if (m.rows == this->rows && m.cols == this->cols)
	{
		return (*this) -= m;
	}
	cout << "Can't subtract different matrices(4)" << endl;
	exit(0);
}

template<class T>
Matrix<T>& Matrix<T>::operator*=(Matrix<T> m)
{
	if (this->cols == m.rows) {
		Matrix<T> ret(this->rows, m.cols);
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < m.cols; j++) {
				for (int k = 0; k < this->cols; k++) {
					//cout << "ret(" << i << ", " << j << ") += (" << (*this)(i, k) << "*" << m(k, j) << ")" << endl;
					ret(i, j) += ((*this)(i, k) * m(k, j));
					//cout << "ret(" << i << ", " << j << ") ==" << ret(i, j) << endl;
				}
				
			}
		}
		this->cols = m.cols;
		(*this) = ret;
		return *this;
	}
	cout << "this->cols(" << this->cols << ") must be equal m.rows(" << m.rows << ")" << endl;
	exit(0);
}

template<class T>
Matrix<T> Matrix<T>::operator*=(Matrix<T> m) const
{
	if (this->cols == m.rows) {
		Matrix<T> ret(this->rows, m.cols);
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < m.cols; j++) {
				for (int k = 0; k < this->cols; k++) {
					//cout << "ret(" << i << ", " << j << ") += (" << (*this)(i, k) << "*" << m(k, j) << ")" << endl;
					ret(i, j) += ((*this)(i, k) * m(k, j));
				}
			}
		}
		this->cols = m.cols;
		(*this) = ret;
		return *this;
	}
	cout << "this->cols(" << this->cols << ") must be equal m.rows(" << m.rows << ")" << endl;
	exit(0);
}

template<class T>
Matrix<T>& Matrix<T>::operator*(Matrix<T> m)
{
	return (*this) *= m;
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> m) const
{
	return (*this) *= m;
}

template<class T>
Matrix<T>& Matrix<T>::operator*=(T num)
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			(*this)(i, j) = (*this)(i, j) * num;
	return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator*=(T num) const
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			(*this)(i, j) = (*this)(i, j) * num;
	return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator*(T num)
{
	return (*this) *= num;
}

template<class T>
Matrix<T> Matrix<T>::operator*(T num) const
{
	return (*this) *= num;
}

template<class T>
Matrix<T> Matrix<T>::hadamard(Matrix<T> m1, Matrix<T> m2)
{
	if (m1.rows == m2.rows && m1.rows == this->rows && m1.cols == m2.cols && m1.cols == this->cols) {
		for (int i = 0; i < m1.rows; i++)
			for (int j = 0; j < m1.cols; j++)
				(*this)(i, j) = m1(i, j)*m2(i, j);
		return *this;
	}
	cout << "Different matrix sizes(hadamard)" << endl;
	exit(0);
}

template<class T>
Matrix<T> Matrix<T>::kronecker(Matrix<T> m1, Matrix<T> m2)
{
	if (kroneckerR(m1, m2) == this->rows && kroneckerC(m1, m2) == this->cols) {
		for (int i = 0; i < m1.getRows(); i++) {
			for (int j = 0; j < m1.getCols(); j++) {
				for (int k = 0; k < m2.getRows(); k++) {
					for (int l = 0; l < m2.getCols(); l++) {
						(*this)(i*m2.rows + k, j*m2.cols + l) = m1(i, j)*m2(k, l);
					}
				}
			}
		}
		return *this;
	}
	cout << "Incorrect size(kronecker)" << endl;
	exit(0);
}

template<class T>
Matrix<T> Matrix<T>::concatOf(Matrix<T> m1, Matrix<T> m2)
{
	if (m1.rows == m2.rows) {
		this->rows = m1.rows;
		this->cols = m1.cols + m2.cols;
		for (int i = 0; i < m1.rows; i++) {
			for (int j = 0; j < m1.cols; j++) {
				(*this)(i, j) = m1(i, j);
			}
			for (int j = 0; j < m2.cols; j++) {
				(*this)(i, j + m1.cols) = m2(i, j);
			}
		}
		return *this;
	}
	cout << "Number of rows must be equal(concatOf)" << endl;
	exit(0);
}

template<class T>
size_t kroneckerR(Matrix<T> m1, Matrix<T> m2)
{
	return m1.getRows()*m2.getRows();
}

template<class T>
size_t kroneckerC(Matrix<T> m1, Matrix<T> m2)
{
	return m1.getCols()*m2.getCols();
}

template<class T>
Matrix<T> Matrix<T>::transpose()
{
	Matrix<T> temp(this->cols, this->rows);

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			temp(j, i) = (*this)(i, j);
		}
	}
	int tmp = this->rows;
	this->rows = this->cols;
	this->cols = tmp;
	(*this) = temp;
	return *this;
}


template<class T>
inline void Matrix<T>::print(int precision)
{
	try {
		for (int i = 0; i < (int)rows; i++) {
			for (int j = 0; j < (int)cols; j++) {
				cout << setw(precision) << data.at(i*cols + j) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

