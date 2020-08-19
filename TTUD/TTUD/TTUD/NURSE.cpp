#include<iostream>;
using namespace std;
int N, k1, k2;
int x[1001];
int appear[1001];
int ans = 0;
void input() {
	cin >> N >> k1 >> k2;
}
bool check(int i, int num) {
	if (num == 1) return true;
	if (x[num - 1] == 0 && i == 0) return false;
	return true;
}

void solution() {
	cout << "solution:  ";
	for (int i = 1; i <= N; i++) {
		cout << x[i] << "  ";
	}
	cout << endl;
}

bool approve() {
	int dem = 0;
	for (int i = 1; i <= N; i++) {
		if (x[i] == 0) {
			dem++;
			appear[dem] = i;
		}
	}
	if (dem==0) return false;
	appear[0] = 0;
	appear[dem+1] = N + 1;
	for (int i = 0; i<=dem; i++) {
		if (i == 0 && appear[1] == 1) continue;
		if (i == dem && appear[dem] == N) continue;
		if ((appear[i + 1] - appear[i] - 1)<k1 || (appear[i + 1] - appear[i] - 1)>k2) return false;
	}
	return true;
}
void TRY(int num) {
	for (int i = 0; i <= 1; i++) {
		if (check(i, num)) {
			x[num] = i;
			if (num == N) {
				if (approve()) ans++;
			}
			else {
				TRY(num + 1);
			}
		}
	}
}
int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
	TRY(1);
	cout << ans;
}