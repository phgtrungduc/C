#include<bits/stdc++.h>
using namespace std;
int x[10002];
int y[10002];
int n,m;
int mem[10002][10002];
void input() {
    cin >>n>>m;
    for (int i=1; i<=n; i++) {
        cin >> x[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> y[i];
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            mem[i][j]=-1;
        }
    }
}
int lcs (int i,int j) {
    if (i == 0 || j == 0) {
        return 0;
    }
    if ( mem[i][j ] != -1) {
        return mem[i][j];
    }
    int res = 0;
    res = max(res, lcs (i, j - 1));
    res = max(res, lcs (i - 1, j));
    if (x[i] == y[j ]) {
        res = max(res, 1 + lcs(i - 1, j - 1));
    }
    mem [i][j ] = res;
    return res;
}

void calc(){
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                mem[i][j] = 0;
            } else if (x[i] == y[j]) {
                mem[i][j] = 1 + mem[i-1][j-1];
            } else {
                mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
            }
        }
    }

}

int main() {
    //freopen("E://abc.txt","r",stdin);
    iostream::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << lcs(n,m);
}
