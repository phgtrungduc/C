#include<bits/stdc++.h>
using namespace std;
int n,k;
int l[5003];
int r[5003];
bool visited[5003];
vector <pair<int,int>>x;
int res[5003];

int w=0;

bool picture[5003];

long long ans = 0;

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}

void input() {
    cin >>n>>k;
    for (int i=1; i<=k; i++) {
        cin >> l[i]>>r[i];
        if ((r[i]-l[i]+1)>w) w=r[i]-l[i]+1;
        x.push_back(make_pair(l[i],r[i]));
    }
    memset(visited,false,sizeof(visited));
    sort(x.begin(),x.end(),cmp);
    res[0]=0;
}

long long solution(){
    memset(picture,false,sizeof(picture));
    long long S = 0;
    for (int i=0;i<k-2;i++){
        for (int i=)
    }
    return S;
}

int dem =0;

long long calc(){
    for (int i=0;i<k;i++){
        dem++;
        for (int j=i-(k-2);j<i;j++)
    }
}
int main() {
    freopen("E://Bai3.txt", "r", stdin);
    iostream::sync_with_stdio(false);
    cin.tie(0);
    input();
    for (int i=0;i<k;i++){
        cout << x[i].first<<"  "<<x[i].second<<endl;
    }
}


