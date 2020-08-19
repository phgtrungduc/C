#include<iostream>
using namespace std;
#define MAX 12
int n;
int c[2 * MAX + 1][2 * MAX + 1];
int x[MAX + 1];
int c_min = 99999;
bool visited[MAX + 1];
int current_value = 0;
int best = 999999;
int scout = 0;

void input() {
	cin >> n;
	for (int i = 0; i <= 2 * n; i++) {
		for (int j = 0; j <= 2 * n; j++) {
			cin >> c[i][j];
			if (i != j) c_min = c_min < c[i][j] ? c_min : c[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
		x[i] = 0;
	}
}

int count(int n) {
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == true) {
			if (i == 1) temp += c[0][x[i]];
			else {
				int prepick = x[i - 1];
				int predrop = x[i - 1] + n;
				temp += (c[predrop][x[i]] + c[prepick][predrop]);
				if (i == n) {
					temp += c[x[i]][x[i] + n];
					temp += c[x[i] + n][0];
				}
			}
		}
	}
	return temp;
}


void solution() {
	for (int i = 1; i <= n; i++) {
		cout << x[i] << "   ";
	}
	cout << endl;
}

void TRY(int num) {
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			x[num] = i;
			visited[i] = true;
			if (num == 1) scout += c[0][x[num]];
			else {
				scout += c[x[num - 1]][x[num-1]+n];
				scout += c[x[num - 1]+n][x[num]];
			}
			
			if (num == n) {
				int temp = count(n);
				if (temp < best) best = temp;
			}
			else {
				if (scout < best) TRY(num + 1);
			}
			visited[i] = false;
			if (num == 1) scout -= c[0][x[num]];
			else {
				scout -= c[x[num - 1]][x[num - 1] + n];
				scout -= c[x[num - 1] + n][x[num]];
			}
		}
	}
}

int main() {
	/*freopen("e:\\abc.txt", "r", stdin);*/
	input();
	TRY(1);
	cout << best;
}