/*
 *  Problem : cvrpcount.cpp
 *  Description :
 *  Created by ngocjr7 on [2020-04-08 10:32]
*/
#include <bits/stdc++.h>
using namespace std;
const long N = 100000 + 7;
const long INF = 1000000000 + 7;
const long MODULE = 1000000000 + 7;
typedef pair<int, int> ii;
int n, k, q;
int a[N];
int x[N];
int s[N];
int factorial[N];
int nt[N];
int ans = 0;
void search(int i)
{
    if (i > n) {
        int res = 1;
        for (int j = 1; j <= k; j++)
            res = res * factorial[nt[j]];
        ans = ans + res;
        return;
    }
    else {
        for (int j = 1; j <= k; j++)
            if (s[j] + a[i] <= q) {
                x[i] = j;
                s[j] += a[i];
                nt[j] += 1;
                search(i + 1);
                s[j] -= a[i];
                nt[j] -= 1;
            }
    }
}
int main()
{
    // freopen("in.txt","r",stdin);
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    factorial[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = factorial[i - 1] * i;
    factorial[0] = 0;
    search(1);
    cout << ans / factorial[k];
    return 0;
}