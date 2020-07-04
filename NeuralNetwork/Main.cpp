// NeuralNet work.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Header.h"
#include <iostream>
#include "Matrix.cpp"

using namespace std;

int main()
{
	vector<double> vect; 
	vector<double> vect2; 
	for (int i = 0; i < 16; i++) {
		vect. push_back((rand() % 500)/10.0 - 15);
		vect2.push_back((rand() % 500)/10.0 - 15);
	}
	Matrix<double> mat(4, 4, vect);
	mat.print(5);
	Matrix<double> mat2(4, 4, vect2);
	mat2.print(5);
	Matrix<double> mat3(4, 4);

	mat3 = mat - mat2;
	mat3.print(5);

	mat. ~Matrix();
	mat2.~Matrix();
	mat3.~Matrix();
	
	//cout << factorial(4)<< endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

