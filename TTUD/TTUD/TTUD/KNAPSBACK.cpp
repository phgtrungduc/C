#include<iostream>
using namespace std;

int n, b;
int c[400 + 1];
int a[30 + 1];
int value = 0;
int weight = 0;
int best = -1;
void input() {
	cin >> n >> b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
}

void TRY(int num) {
	for (int i = 1; i >= 0; i--) {
		if (weight + i*a[num]<=b) { //ghi nho la <= vi khoi luong do vat van co the bang khoi luong cua tui
			value += i*c[num];
			weight += i*a[num];
			if (num == n) {
				best = best > value ? best : value;
			}
			else {
				TRY(num + 1);
			}
			value -= i * c[num];
			weight -= i * a[num];
		}
	}
}

int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
	TRY(1);
	cout << best;
}
