#include "pch.h"
#include "Header.h"
#include <iostream>
#include "Matrix.cpp"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>  
#include "gnuplot_c.c"


#define X_MIN		-5.0                             
#define X_MAX		5.0
#define Y_MIN		0.0
#define Y_MAX		1.0

h_GPC_Plot *h2DPlot1;                // Declare plot object
h_GPC_Plot *Plot2D;                // Declare plot object


												// Declare an arry of fun colours to use
const char *plotColour[] = { "purple", "green", "blue", "black", "orange", "cyan", "violet", "grey", "magenta", "light-red" };

char graphTitle[40];


int main()
{
	int n = 69;
	Point* arr;
	arr = (Point*)malloc(sizeof(Point)*n);
	for (int i = 0; i < n; i++) {
		(*(arr + i)).xVal = i - 15;
		(*(arr + i)).yVal = rand() % 69 - 15;
	}

	Plot2D = gpc_init_2d_("Plot",
		"x",
		"f(x)",
		GPC_AUTOSCALE_X,
		0.0,
		10.0,
		-140.0,
		600.0,
		GPC_IGNORE);
	if (Plot2D == NULL) {
		cout << "Plot creation failure" << endl;
		exit(1);
	}


	/*
	gpc_graph_plot(h2DPlot1,		
		"1/(1+exp(-x))",       
		X_MIN,
		X_MAX,             
		Y_MIN,
		Y_MAX,          
		"#ff1a1a");
		*/
	gpc_plot_by_points(Plot2D,
		"Random function",
		n,
		arr,
		-15.0,
		50.0,
		-15.0,
		50.0,
		"lines",
		"#ff0000");
	printf("\nHit <Carriage Return> to continue ....\n"); getchar();
	gpc_close(h2DPlot1);
	return 0;
}



/*
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
	cout << "   " << endl;
	//cout << factorial(4)<< endl;
	return 0;
	
}
*/


