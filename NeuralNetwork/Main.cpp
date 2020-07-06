#include "pch.h"
#include "Header.h"
#include <iostream>
#include "Matrix.cpp"

using namespace std;

int main()
{
	vector<double> vect; 
	vector<double> vect2; 
	for (int i = 0; i < 15; i++) {
		vect. push_back(rand() % 50 - 15);
	}
	for (int i = 0; i < 18; i++) {
		vect2.push_back(rand() % 50 - 15);
	}
	Matrix<double> mat (3, 5, vect);
	mat.print(5);
	Matrix<double> mat2(3, 6, vect2);
	mat2.print(5);
	Matrix<double> mat3(kroneckerR(mat, mat2), kroneckerC(mat, mat2));

	mat3.concatOf(mat, mat2);
	mat3.print();


	mat. ~Matrix();
	mat2.~Matrix();
	mat3.~Matrix();
	cout << " " << endl;
	//cout << factorial(4)<< endl;
	return 0;
	
}



