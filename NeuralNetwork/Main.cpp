#include "pch.h"
#include "Header.h"
#include <iostream>
#include "Matrix.cpp"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>  
#include "gnuplot_c.c"

#define SAMPLE_LENGTH     100
#define X_MIN             0.0                             // Minimum X value
#define X_MAX             ((double)(SAMPLE_LENGTH - 1))   // Maximum X value

h_GPC_Plot *h2DPlot1, *h2DPlot2;                // Declare plot object


												// Declare an arry of fun colours to use
const char *plotColour[] = { "purple", "green", "blue", "black", "orange", "cyan", "violet", "grey", "magenta", "light-red" };

char graphTitle[40];

double Array[SAMPLE_LENGTH];

int main()
{
	int i, j;

	h2DPlot1 =                                  // Initialize plot
		gpc_init_2d("Data plot",               // Plot title
			"x",                    // X-Axis label
			"f(x)",               // Y-Axis label
			//20.0,                      // Scaling mode
			GPC_AUTO_SCALE,            // Scaling mode
			GPC_SIGNED,                // Sign mode
			GPC_KEY_ENABLE);           // Legend / key mode

	if (h2DPlot1 == NULL)                       // Plot creation failed - e.g is server running ?
	{
		printf("\nPlot creation failure. Please ensure gnuplot is located on your system path\n");
		exit(1);
	}

	for (i = 0; i < SAMPLE_LENGTH; i++)     // Fill the array
	{
		Array[i] = i * log2(i);
	}
	gpc_graph_plot(h2DPlot1,		// Plot handle
		"sin(x)/(x**2)",
		SAMPLE_LENGTH,         // Number of data points
		graphTitle,            // Dataset title
		X_MIN,                 // Minimum X value
		X_MAX,                 // Maximum X value
		"lines",               // Plot type
		plotColour[0]);
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


