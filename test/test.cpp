#include <iostream>
using namespace std;

void Perm(double list[], int k, int m) {
	if(k == m) {
		for(int i = 0; i <= m; i++)
			cout <<  list[i];
			cout << endl;
	} else {
		for(int i = k; i <= m; i++) {
			swap(list[k], list[i]);
			Perm(list, k + 1, m);
			swap(list[k], list[i]);
		}
	}
}

void swap(double &a, double &b) {
	double temp = a;
	a = b;
	b = temp;
}

int main() {
	double list[5] = {1, 2, 3, 4, 5};
	Perm(list, 0, 4);
	return 0;
}
