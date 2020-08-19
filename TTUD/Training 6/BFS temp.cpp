
#include<bits/stdc++.h>
using namespace std;

int n,m;
bool visited[1000005];
vector <int> a[1000005];
int d[1000005];
void input() {
    cin >>n>>m;
    for (int i=0; i<m; i++) {
        int u,v;
        cin >>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(visited,false,sizeof(visited));
}

void BFS(int start) {
    queue<int>qu;
    qu.push(start);
    visited[start]=true;
    while(!qu.empty()) {
        int u = qu.front();
        cout <<u<<"  ";
        qu.pop();
        for (int i=0;i<a[u].size();i++) {
            if (!visited[a[u][i]]) {
                visited[a[u][i]]=true;
                qu.push(a[u][i]);
            }
        }
    }
}

void BFS_d(int start){
    queue<int>qu;
    qu.push(start);
    d[start]=0;
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (int i=0;i<a[u].size();i++) {
                int v = a[u][i];
            if (d[v]>d[u]+1) {
                d[v]=d[u]+1;
                qu.push(v);
            }
        }
    }
}

int main() {
    freopen("E://abc.txt","r",stdin);
    input();
    for (int i=1;i<=n;i++){
        d[i]=1e9;
    }
    BFS_d(1);
    for (int i=1;i<=n;i++){
        cout <<"i: "<<i<<"  "<< d[i]<<endl;
    }
}
