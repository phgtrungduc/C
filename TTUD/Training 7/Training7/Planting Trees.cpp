#include<bits/stdc++.h>
using namespace std;
int n;
int x[100005];
void input() {
    cin>>n;
    for (int i=1;i<=n;i++){
        cin >>x[i];
    }
}
bool cmp (int a,int b){
    return a>b;
}
void calc(){
    sort(x+1,x+n+1,cmp);

    long long now =1;
    long long best =0;
    for (int i=1;i<=n;i++){
        if (now+x[i]>best){
            best = x[i]+now;
        }
        now ++;
    }
    cout << best+1;
}

int main() {
	//freopen("E://abc.txt", "r", stdin);
	input();
	calc();
}
