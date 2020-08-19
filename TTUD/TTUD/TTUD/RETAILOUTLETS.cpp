#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[107];
int f[107][107];
void input() {
    cin >>n>>m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}
//int dp(int i,int j) {
//    if (i==1) {
//        if (j%a[i]==0) return 1;
//        else return 0;
//    }
//    int k=1;
//    int temp = 0;
//    while (k*a[i]<j) {
//        temp += dp(i-1,j-k*a[i]);s
//        k++;
//    }
//
//    return temp;
//}
void calc() {
    f [0][0] = 1;
    for ( int i = 1; i <= n ; ++ i ) {
        for ( int j = a [ i ]; j <= m ; ++ j ) {
            for ( int k = j - a [ i ]; k >= 0; k -= a [ i ]) {
                f [ i ][ j ] += f [ i - 1][ k ];
            }
        }
    }
}
int main() {
    //freopen("E:\\abc.txt", "r", stdin);
    input();
    calc();
    cout << f[n][m];
}
