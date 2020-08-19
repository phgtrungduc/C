#include<iostream>
using namespace std;
int n, k, o;
bool* visited;
int check = false;
int dem = 0;
int* x;
void input() {
	cin >> n >> k>>o;
	x = new int[n + 1];
	visited = new bool[n + 1];
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
}
void solution() {
	for (int i = 1; i <= n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}
bool checko() {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= i + o - 1; j++) {
			if (a[j])
		}
	}
}
void TRY(int num) {
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			x[num] = i;
			visited[i] = true;
			if (num == n) {
				dem++;
				if (dem == k) {
					check = true;
					solution();
					return;
				}
			}
			else {
				if (dem < k)TRY(num + 1);
			}
			visited[i] = false;
		}
	}
}
int main() {
	input();
	TRY(1);
	if (check == false) cout << -1;
}