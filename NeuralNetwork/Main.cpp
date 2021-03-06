#include "pch.h"
#include "Header.h"
#include <iostream>
#include "Matrix.cpp"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>  

// #include "gnuplot_c.c"
/*
	int n = 69;
	Point* arr;
	arr = (Point*)malloc(sizeof(Point)*n);
	for (int i = 0; i < n; i++) {
		(*(arr + i)).xVal = i - 15;
		(*(arr + i)).yVal = rand() % 10 - 5;
	}

	h_GPC_Plot *Plot2D;               

	Plot2D = gpc_init_2d_("Plot",
		"x",
		"f(x)",
		GPC_AUTOSCALE,
		0.0,
		10.0,
		-140.0,
		100.0,
		GPC_TOP);
	if (Plot2D == NULL) {
		cout << "Plot creation failure" << endl;
		exit(1);
	}

	gpc_plot_by_points(Plot2D,
		"Random function",
		n,
		arr,
		"lines",
		"#ff0000");
	gpc_graph_plot(Plot2D,
		"1/(1+exp(-x))",
		"#ff1a1a");
	gpc_graph_plot(Plot2D,
		"sin(x)",
		"rand");

	printf("\nHit <Carriage Return> to continue ....\n"); getchar();
	gpc_close(Plot2D);
*/




using namespace std;

int main()
{
	vector<double> vect; 
	vector<double> vect2; 
	for (int i = 0; i < 15; i++) {
		vect. push_back((rand() % 2000-1000)/100.0);
	}
	for (int i = 0; i < 15; i++) {
		vect2.push_back(rand() % 50 - 15);
	}
	Matrix<double> mat1 (3, 5, vect);
	//mat1.print(5);
	Matrix<double> mat2(3, 5, vect2);
	//mat2.print(5);
	Matrix<double> mat3(1, 1);
	Matrix<double> mat4(1, 1);
	
	//mat3 = activation_der1(mat1);
	//mat3.print(2);
	//mat4 = activation_der1(mat1);
	mat1 *= 2.2343;
	mat3.hadamard(mat1, mat2);
	cout << "test" << endl;
	mat1.print();
	mat2.print();
	mat3.print();


	mat1.~Matrix();
	mat2.~Matrix();
	mat3.~Matrix();
	mat4.~Matrix();
	cout << "               " << endl;
	return 0;
}



