#include<iostream>
using namespace std;

int x[13];
bool cot[13], hang[13], cheocong[26], cheotru[26];
int N, M;
int dem;
int hole[13][13];
void solution() {
	for (int i = 1; i <= N; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}
bool check(int i, int j) {
	if (hang[i] == true) return false;
	if (cot[j] == true) return false;
	if (cheocong[i + j] == true) return false;
	if (cheotru[i - j + 13] == true) return false;
	if (hole[i][j] == 1) return false;
	return true;
}
void TRY(int num) {
	for (int i = 1; i <= N; i++) {
		if (check(num, i) == true) {
			x[num] = i;
			hang[num] = true;
			cot[i] = true;
			cheocong[num + i] = true;
			cheotru[num - i + 13] = true;
			if (num == N) {
				dem++;
			}
			else {
				TRY(num + 1);
			}
			hang[num] = false;
			cot[i] = false;
			cheocong[num + i] = false;
			cheotru[num - i + 13] = false;
		}
	}
}

void input() {
	do {
		cin >> N >> M;
		int first, second;
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 12; j++) {
				hole[i][j] = 0;
			}
		}
		for (int i = 0; i < M; i++) {
			cin >> first;
			cin >> second;
			hole[first][second] = 1;
		}
		dem = 0;
		TRY(1);
		if (N != 0 || M != 0) cout << dem << endl;
	} while (N!=0||M!=0);
}
int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
}