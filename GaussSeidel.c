#include <stdio.h>
#include "createMatrix.c"
#include "printAndScanMatrix.c"


void gaussSeidel(double **A, double *b, double *x, int n, int imax, float es, float lambda){
	//initial value of variable is zero
	for (int i = 0; i < n; ++i)
	{
		x[i] = 0;
	}

	int converge = 1;
	int k=0;
	while(1){
		printf("Iteration:%d \n", k);
		converge = 1;

		for (int i = 0; i < n; ++i)
		{
			double old = x[i];
			//sum
			double summation = b[i];
			for (int j = 0; j < n; ++j)
			{
				if (j != i)
				{
					summation -= A[i][j]*x[j];
				}
			}

			//store in new value of variables
			x[i] = summation/A[i][i];
			x[i] = lambda*x[i] + (1 - lambda)*old;   //weighted average of old and new value of x[i]
			printf("old = %f x[%d] = %f \t", old, i, x[i]);
			double diff = old - x[i];
			if(diff < 0)
				diff = -1*diff;
			printf("diff = %f\t",diff);
			if(converge == 1 && x[i] != 0){
				float ea = (diff*100.0)/x[i];
				printf("ea[%d] = %f \t", i, ea);
				if (ea > es)
				{
					converge = 0;
				}
			}
		}

		printf("\n");
		k++;
		if (converge == 1 || k > imax)
		{
			break;
		}	
	}
}


void main(){

	//take dimension of A(coefficient matrix) from user
	int n = 0;
	printf("Enter dimension of square matrix A\n");
	scanf("%d", &n);

	//create matrix A
	double **A = createMatrix(n, n);
	printf("Enter coefficient matrix \n");
	scanMatrix(A, n, n);
	printMatrix(A, n, n);

	//create matrix b
	double b[n];

	//read b matrix
	printf("Enter b matrix\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf", &b[i]);
	}

	//print b
	for (int i = 0; i < n; ++i)
	{
		printf("%f \t", b[i]);
	}

	//create matrix x, which holds current value of variables
	double x[n];

	//print solution
	for (int i = 0; i < n; ++i)
	{
		printf("%.4f \t", x[i]);
	}
	printf("\n");

	gaussSeidel(A, b, x, n, 100, 1, 1);
}


