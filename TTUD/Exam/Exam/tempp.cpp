#include<bits/stdc++.h>
using namespace std;
string S;
int k,n;
int result[100006];
int ans [100006];
void input() {
    getline(cin,S);
    cin >>k;
    n = S.length();
    memset(result,-1,sizeof(result));
}

int opt( int i, int x) {
    if (i==x+1){
        int temp =0;
        for (int j=0;j<=x;j++){
            temp +=S[j];
        }
    return temp;
    }
    if (i ==1) {
        int temp = 0;
        for (int j=0; j<=x; j++) {
            if (temp < S[j]) temp =S[j];
        }
        return temp;
    }
    if (result[i]!=-1) return result[i];
    int res = 0;
    res = max(res, S[x] + opt(i-1, x-1));
    res = max(res, opt (i, x-1));
    result[i]=res;
    return res;
}
void trace(int i,int x){
    if (i==x+1){
        int temp =0;
        for (int j=0;j<=x;j++){
            ans[j]=res[j];
        }
    }
    if (i ==1) {
        int temp = 0;
        for (int j=0; j<=x; j++) {
            if (temp < S[j]) temp =S[j];
        }
        ans[0]= temp;
    }

    int res = 0;
    if (result[i]=S[x]+result[])
    res = max(res, S[x] + opt(i-1, x-1));
    res = max(res, opt (i, x-1));
    return res;
}

int main() {
    freopen("E://Bai2.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    cout << opt(k,n-1)<<endl;
    cout<<'x'+'d';
}

