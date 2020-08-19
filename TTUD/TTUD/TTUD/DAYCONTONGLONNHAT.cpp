#include <iostream>
#include<minmax.h>
using namespace std;
#define MAX 50
int x[MAX];
int n;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
}
int PL(int l,int r) {
	int s = 0;
	int best = -999999;
	for (int i = r; i >= l; i--) {
		s += x[i];
		best = best > s ? best : s;
	}
	return best;
}
int PR(int l, int r) {
	int s = 0;
	int best = -999999;
	for (int i = l; i <= r; i++) {
		s += x[i];
		best = best > s ? best : s;
	}
	return best;
}
int P(int l, int r) {
	if (l == r) return x[r];
	else {
		int m = (l + r) / 2;
		return max(max (PL(l, m), PR(m + 1, r)), PL(l, m)+ PR(m + 1, r));
	}
}

int main() {
	input();
	cout << P(0, n - 1);
}