#include<bits/stdc++.h>
using namespace std;
int f,s,g,up,down;
bool visited[1000005];

vector <int>a[1000005];

int d[1000005];
void input() {
    cin >> f>>s>>g>>up>>down;
    for (int i=1; i<=f; i++) {
        if (i+up<=f) {
            a[i].push_back(i+up);
        }
        if (i-down>=1) {
            a[i].push_back(i-down);
        }
    }
}
void BFS_d(int start) {
    for (int i=1; i<=f; i++) {
        d[i]=1e9;
    }
    queue<int>qu;
    qu.push(start);
    d[start]=0;
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (int i=0; i<a[u].size(); i++) {
            int v = a[u][i];
            if (d[v]>d[u]+1) {
                d[v]=d[u]+1;
                qu.push(v);
            }
        }
    }
}

int main() {
    //freopen("E://abc.txt","r",stdin);
    input();
//    for (int i=1;i<=f;i++){
//        for (int j=0;j<a[i].size();j++){
//            cout <<a[i][j]<<"  ";
//        }
//        cout << endl;
//    }
    BFS_d(s);
    if  (d[g]!=1e9){
        cout << d[g];
    }else {
        cout << "use the stairs";
    }
}


