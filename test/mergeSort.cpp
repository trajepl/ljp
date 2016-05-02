#include <iostream>
using namespace std;

template <class  T>
void MergeSort(T a[], int left, int right) {
    if(left < right) {
        int i = (left + right) / 2;
        MergeSort(a, left, i);
        MergeSort(a, i + 1, right);
        Merge(a, b, left, i, right);
        Copy(a, b, left, right);
    }
}

template <class T>
int partition (T a[], int p, int r) {
    int i = p, j = r + 1;
    T x = a[p];

    while(true) {
        while(a[++i] < x);
        while(a[--j] > x);
        if(i >= j) break;
        swap(a[i], a[j]);
    }
    a[p] = a[j];
    a[j] = x;
    return j;
}

template <class T>
void Merge(T c[], T d[], int l, int m, int r) {
    int i = l, j = m + 1; k = l;
    while( i <= m && j <= r) {
        if(c[i] <= c[j]) d[k++] = c[i++];
        else d[k++] = c[j++];
    }
    if(i > m) 
        for(int q = j; q <= r; q++) d[k++] = c[q];
    else
        for(int q = i; q <= m; q++) d[k++] = c[q];
}

int main() {
    double a[] = {1, 4, 3, 2, 6};

}