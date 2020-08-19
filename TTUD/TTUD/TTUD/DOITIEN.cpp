#include<iostream>
#include<algorithm>
using namespace std;
int n, x;
int d[100];
void input() {
    cin >> n>>x;
    for (int i= 1; i <= n; i++) {
        cin >> d[i];
    }
}

int opt( int i, int x ) {
    if (x < 0) return 1e9;
    if (x == 0) return 1;
    if (i ==1) {
        if (x%d[i]==0) return x/d[1];
        else return 1e9;
    }

    int res = 1e9;
    res = min(res, 1 + opt(i, x - d[i]));
    res = min(res, opt (i - 1, x));
    return res;
}


int main() {
    freopen("E://abc.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    cout << opt(n,x);
}
