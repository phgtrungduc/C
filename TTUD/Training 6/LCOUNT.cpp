#include<bits/stdc++.h>
using namespace std;
vector<int>a[100005];
bool visited[100005];
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
int dem =0;
void DFS(int u){
    visited[u]=true;
    int count = 0;
    for(int v:a[u]){
        if (!visited[v]){
                count++;
            DFS(v);
        }
    }
    if (count==0) dem++;
}
int main(){
    freopen("E://abc.txt","r",stdin);
    input();
    DFS(1);
    cout <<dem;
}

