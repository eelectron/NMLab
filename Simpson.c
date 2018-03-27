/*
Approximate area = (h/3)*[f(x0) + 4*f(x1) + 2*f(x2) + ... + 2*f(x(n-2)) + 4*f(x(n-1)) + f(xn)]
*/

#include<stdio.h>
#include<math.h>

//prototype
float f(float x);
float simpson(float lm, float um, int n);

int main(){
	
	float lm = 4;    	//lower limit
	float um = 5.2; 	//upper limit
	int n;				//no. of interval

	printf("Enter no. of interval\n");
	scanf("%i", &n);

	float area = simpson(lm, um, n);
	printf("approximate area = %f\n", area);
}


/*
 Function over which we want to integrate.
 Here , taking log() function to approximate.
 But it can be replaced over any other function.
 x: x value at which function value will be calculated.
 return : f(x)
*/
float f(float x){
	return log(x);
}


/*
Approximate the area using Simpson's 1/3 rule.
lm: lower limit of integration
um: pper limit of integration
n: no. of interval. It should be even because we need to interval to
	form one quadratic approximation.

return: approximate area under the curve.
*/
float simpson(float lm, float um, int n){
	//find width of each interval
	float h = (um - lm)/n;


	//calc. approximate area
	float area = 0;
	float x;
	for (int i = 0; i <= n; ++i)
	{	
		x	= lm + i*h;
		if(i == 0 || i == n)
			area = area + f(x);
		else if(i % 2 == 0)
			area = area + 2*f(x);
		else
			area = area + 4*f(x);
	}

	area = (h/3)*area;
	return area;
}