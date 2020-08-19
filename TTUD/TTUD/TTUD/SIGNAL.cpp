#include<iostream>
#include <algorithm> 
using namespace std;

//int findMax(int *a, int start,int end) {
//	int max = INT32_MIN;
//	for (int i = start; i <= end; i++) {
//		if (a[i] > max) max = a[i];
//	}
//	return max;
//}
//int timViTri(int *a, int n,int b) {
//	int max = INT32_MIN;
//	bool check=false;
//	for (int i=1;i<n-1)
//	for (int i = 1; i < n-1; i++) {
//		int temp1 = findMax(a, 0, i - 1);
//		int temp2 = findMax(a, i + 1, n - 1);
//		if ((temp1 - a[i]) >= b && (temp2 - a[i])>= b) {
//			if ((temp1 + temp2 - 2 * a[i]) > max) {
//				max = (temp1 + temp2 - 2 * a[i]);
//				check = true;
//			}
//		}
//	}
//	if (check == false) return -1;
//	else return max;
//}

int main() {
	int n, b;
	cin >> n >> b;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int* minFront = new int[n];
	int* minAfter = new int[n];
	minFront[0] = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > minFront[i - 1]) minFront[i] = a[i];
		else minFront[i] = minFront[i - 1];
	}
	minAfter[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > minAfter[i + 1]) minAfter[i] = a[i];
		else minAfter[i] = minAfter[i + 1];
	}

	int max = INT32_MIN;
	bool check = false;

	for (int i = 1; i < n - 1; i++) {
		int temp1 = minFront[i];
		int temp2 = minAfter[i];
		if ((temp1 - a[i]) >= b && (temp2 - a[i]) >= b) {
			if ((temp1 + temp2 - 2 * a[i]) > max) {
				max = (temp1 + temp2 - 2 * a[i]);
				check = true;
			}
		}
	}
	if (check == false) cout << -1;
	else cout << max;
}