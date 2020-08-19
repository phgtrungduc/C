#include<iostream>
#include<algorithm>
using namespace std;
int n, L1, L2;
int x[100000];
int result[100000];
int best = 0;
void input() {
	cin >> n >> L1 >> L2;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		result[i] = false;
	}
}

void compute() {
	for (int i = 0; i < n; i++) {
		int temp = x[i];
		for (int j = 0; j < i; j++) {
			int chiso = i - j;
			if (L1 <= chiso && chiso <= L2) {
				temp = max(temp, result[j] + x[i]);
			}
		}
		result[i] = temp;
	}
	for (int i = 0; i < n; i++) {
		best = max(best, result[i]);
	}
	cout << best;
}


int main() {
	int x[] = { 1,2,3 };
	do {
		cout << x[0] << " " << x[1] << " " << x[2] << endl;
	} while (next_permutation(x, x + 3));
}
