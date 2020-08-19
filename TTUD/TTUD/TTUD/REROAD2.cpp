#include <iostream>
using namespace std;
#include <vector>
int countPhucTap(vector <int>a, int size) {
	int count = 1;
	for (int i = 1; i < size; i++) {
		if (a[i] != a[i - 1]) {
			count++;
		}
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	int *t = new int [n];
	int p, c;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >>t[i];
	}
	int res = 0;
	for (int i = 0; i < n; i++){
		res += (t[i] != t[i - 1]);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> p >> c;
		res += (t[p - 1] == t[p]) + (t[p - 1] == t[p - 2]);
		res +=
	}
}