#include<iostream>
using namespace std;

int x[13];
bool cot[13], hang[13], cheocong[26], cheotru[26];
int N, M;
int ans = 0;
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
				ans++;
				solution();
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
int main() {
	cin >> N;
	TRY(1);
	cout << ans;
}