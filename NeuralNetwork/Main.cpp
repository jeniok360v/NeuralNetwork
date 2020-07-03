// NeuralNet work.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Header.h"
#include <iostream>

using namespace std;

int main()
{

	Matrix* matr = new Matrix(8, 6);
	matr->print();
	
	vector<double> vect; 
	for (int i = 0; i < 16; i++) {
		vect.push_back(rand() % 50 - 15);
	}
	Matrix* matr2 = new Matrix(4, 4, vect);
	matr2->print();
	(*matr2)(2, 2) = 4.3;
	//matr2->data.at(2*4 + 2) = 4;
	matr2->print();

	//cout << factorial(4)<< endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
