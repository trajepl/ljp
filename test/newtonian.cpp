#include<stdio.h>
#include<math.h>

double fx(double x) {
	return x * x - 0.1 * x - 3.06;
}
double fx1(double x) {
	return 2 * x - 0.1;
}

int main() {
	double result = 2;
	double x = 1;
	double x0 = 0;
	int count = 0;
	while(x - result >= 0.01 || x - result <= -0.01) { 
		x0 = x;
		x = result;
		
		result = x - (x - x0) * fx(x) / (fx(x) - fx(x0));
		printf("%d %f\n", count++, result);
		
	}
	return 0;
}
