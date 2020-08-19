#include <iostream>
using namespace std;
void cogang(int *a,int k,int n) {
	for (int i = 0; i <= 1; i++) {
		a[k] = i;
		if (k == n-1) {
			for (int i = 0; i < n; i++) {
				cout << a[i];
			}
			cout << endl;
		}
		else cogang(a, k + 1, n);
	}
}


int main() {
	cout << "Nhap chieu dai day nhi phan: ";
	int n;
	cin  >> n ;
	int * a = new int[n];
	cogang(a,0,n);
}