#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool visited[100005];
struct edges {
    int u,v,weight;
    edges(int _u,int _v,int w) {
        u = _u;
        v= _v;
        weight= w;
    }
};
vector<edges>a[100005];
void input() {
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u,v,w;
        cin >>u>>v>>w;
        a[u].push_back(edges(u,v,w));
        a[v].push_back(edges(v,u,w));
    }
}
long long ans =0;
long long S =0;
int dinh =-1;
void DFS(int u) {
    for (int i=0; i<a[u].size(); i++) {
        visited[u]=true;
        edges e = a[u][i];
        if (!visited[e.v]) {
            S+=e.weight;
            if (S>ans) {
                ans = S;
                dinh = e.v;
            };
            DFS(e.v);
            S-=e.weight;
        }

    }
}
int main() {
    //freopen("E://abc.txt","r",stdin);
    iostream::sync_with_stdio(false);
    cin.tie(0);
    input();
    DFS(1);
    S =0;
    ans =0;
    memset(visited,false,sizeof(visited));
    DFS(dinh);
    cout <<ans;
}
