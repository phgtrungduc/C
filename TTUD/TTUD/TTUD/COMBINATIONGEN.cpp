#include<iostream>
using namespace std;
int m;
int n;
int x[10003];
bool visited[10003];
int ans = 0;
void input() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x[i];
	}
}
void solution() {
	for (int i = 1; i <= m; i++) {
		cout << x[i] << " ";
	}
}
bool compute() {
	int vitri = -1;
	for (int i = m; i >= 1; i--) {
		if (x[i] < n - (m - i)) {
			vitri = i;
			break;
		}
	}
	if (vitri == -1) return false;
	else {
		if (vitri != 1) {
			x[vitri]++;
		}
		else {
			x[1]++;
			for (int i = 2; i <= m; i++) {
				x[i] = x[i - 1] + 1;
			}
		}
		return true;
	}
}

int main() {
	input();
	if (compute() == false) {
		cout << -1;
	}
	else {
		solution();
	}
}