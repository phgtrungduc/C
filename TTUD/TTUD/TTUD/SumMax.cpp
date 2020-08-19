#include<iostream>
using namespace std;

int maxSum(int *a,int n) {
	int* sum = new int[n];
	sum[0] = a[0];
	int max = sum[0];
	
	for (int i = 1; i < n; i++) {
		if (sum[i-1] < 0) {
			sum[i] = a[i];
			if (sum[i] > max) max = sum[i];
		}
		else {
			sum[i] = sum[i - 1] + a[i];
			if (sum[i] > max) max = sum[i];
		}
	}
	return max;
}


int main() {
	int n;
	
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << maxSum(a,n);
}