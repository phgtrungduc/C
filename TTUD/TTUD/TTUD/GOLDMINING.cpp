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
		result[i] = -1;
	}
}
int gold(int num) {
	if (result[num] != -1) {
		return result[num];
	}
	if (num - L1 < 0) {
		result[num] = x[num];
		return x[num];
	}
	int temp = x[num];
	for (int i = num - L2; i <= num - L1; i++) {
		if (i >= 0) {
			temp = max(temp, gold(i) + x[num]);
		}
		
	}
	result[num] = temp;
	return temp;
}
void compute() {
	for (int i = 0; i < n; i++) {
		gold(i);
	}
	for (int i = 0; i < n; i++) {
		best = max(best, result[i]);
	}
	cout << best<<endl;
}


int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
	compute();
	/*cout << "day ne" << endl;
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}*/
}