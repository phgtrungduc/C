#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int dem;
int dp[1000];
int T = 1;
struct Rec {
	int x, y, z;
	bool operator < (const Rec& a) {
		return (this->x < a.x) && (this->y < a.y);
	}
} a[200];

bool cmp(const Rec a, const Rec b) {
	if (a.x != b.x) return a.x > b.x;
	if (a.y != b.y) return a.y > b.y;
	return a.z > b.z;
}


void input() {
	while (true) {
		int m = 0;
		cin >> n;
		if (n == 0) break;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x[3];
			cin >> x[0] >> x[1] >> x[2];
			sort(x, x + 3);
			do {
				a[++m].x = x[0], a[m].y = x[1], a[m].z = x[2];
			} while (next_permutation(x, x + 3));
		}
		sort(a + 1, a + m + 1, cmp);
		memset(dp, 0, sizeof(dp));

		a[0].x = a[0].y = 1e9, a[0].z = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i] < a[j]) {
					dp[i] = max(dp[i], dp[j] + a[i].z);
				}
			}
			ans = max(ans, dp[i]);
		}
		cout << "Case " << T << ": maximum height = " << ans << endl;
		T++;
	}
}


int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
}