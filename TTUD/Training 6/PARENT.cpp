#include<bits/stdc++.h>
using namespace std;
vector<int>a[100005];
bool visited[100005];
int parent[100005];
int n;
void input() {
    cin >>n;
    for (int i=0; i<n-1; i++) {
        int u,v;
        cin >>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(visited,false,sizeof(visited));
}
void DFS(int u){
    visited[u]=true;
    for(int v:a[u]){
        if (!visited[v]){
            DFS(v);
            parent[v]=u;
        }
    }
}
int main(){
    //freopen("E://abc.txt","r",stdin);
    input();
    DFS(1);
    for (int i=2;i<=n;i++){
        cout << parent[i]<<" ";
    }
}
