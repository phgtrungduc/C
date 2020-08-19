#include<bits/stdc++.h>
using namespace std;

int n, L1, L2;
int dp[100002];
int mdata[100002];

int main() {
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++) {
        cin >> mdata[i];
        dp[i] = mdata[i];
    }
    int ans = 0;
    for (int i = L1 + 1; i <= n; i++) {
        for (int j = i - L2; j <= i - L1; j++) {
            dp[i] = max(dp[i], dp[max(0, j)] + mdata[i]);

        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}