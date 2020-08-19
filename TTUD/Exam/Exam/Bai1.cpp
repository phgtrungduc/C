#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[1003][1003];
int y[1003];
void input() {
    cin >>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> x[i][j];
        }
    }
    cin >>m;
    for (int i=1;i<=m;i++){
        cin >> y[i];
    }
}
void calc(){
    long long S = 0;
    for (int i=1;i<m;i++){
        S +=x[y[i]][y[i+1]];
    }
    cout << S;
}

int main() {
	//freopen("E://Bai1.txt", "r", stdin);
	input();
	calc();
}

