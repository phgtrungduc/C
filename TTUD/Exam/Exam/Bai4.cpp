#include<bits/stdc++.h>
using namespace std;
int n;
int x[1005];

bool cmp(int a,int b){
    return a>b;
}

void input() {
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >>x[i];
    }
    sort(x+1,x+n+1,cmp);
}
void calc(){
    int dem=0;
    for (int i=1;i<=n;i++){
        if (x[i]-x[i+2]<=10&&i+2<=n){
            dem ++;
            i = i+2;
        }
        else if (x[i]-x[i+1]<=20&&i+1<=n){
            dem ++;
            i=i+1;
        }
        else {
            dem++;
        }
    }
    cout << dem;
}

int main() {
	//freopen("E://Bai4.txt", "r", stdin);
	iostream::sync_with_stdio(false);
    cin.tie(0);
	input();
	calc();
}


