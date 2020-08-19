#include<iostream>
using namespace std;
int m;
int n;
int x[10003];
bool visited[10003];
int ans = 0;
void input() {
	cin >> n >> m;
	x[0] = 0;
}

bool check(int i,int num) {
	for (int j = 1; j < num; j++) {
		if (x[j] >= i) return false;
	}
	return true;
}

void solution() {
	for (int i = 1; i <= m; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void TRY(int num) {
	for (int i = x[num-1]+1; i <= n;i++) {
		if (1) {
			x[num] = i;
			visited[i] = true;
			if (num == m) {
				ans++;
				solution();
			}
			else {
				TRY(num + 1);
			}
			visited[i] = false;
		}
	}
}
int main() {
	input();
	TRY(1);
	cout << ans;
}