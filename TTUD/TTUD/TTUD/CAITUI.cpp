#include<iostream>
using namespace std;

int n, b;
int c[400 + 1];
int a[30 + 1];
int value = 0;
int weight = 0;
bool check[30 + 1];
int maxx = 0;
void input() {
	cin >> n >> b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		check[i] = false;
	}

}
void findMax() {
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			if (weight + a[i] <= b) {
				weight += a[i];
				value += c[i];
				check[i] = true;
				maxx = (maxx > value) ? maxx : value;
				findMax();
				weight -= a[i];
				value -= c[i];
				check[i] = false;
			}
		}
	}
}

int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/

	input();
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << c[i][j] << "  ";
		}
		cout << endl;
	}*/
	findMax();
	cout << maxx;
}
