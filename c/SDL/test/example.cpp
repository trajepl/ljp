#include<stdio.h>
#include<math.h>

double f(double x) {
	double swap = 1.0 + x * x;
	double result =pow(swap, 1/3.0);
	return result;
}

int main() { 
	double x = 1;
	double fx = 1.48;
	int count = 0;
	while(fx - x >= 0.01 || fx - x <= -0.01) {
		x = fx;
		fx = f(x);
		printf("%d:	%f\n", count++, fx );
	}
	return 0;
}
