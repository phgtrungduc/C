#include<bits/stdc++.h>
using namespace std;
int n,m;

int f[100005];
bool visited[100005];
int s,t;
struct edges {
    int u,v,weight;
    edges(int _u,int _v,int w) {
        u = _u;
        v= _v;
        weight= w;
    }
};
vector <edges>a[100005];
void input() {
    cin >> n>>m;
    for (int i=0; i<m; i++) {
        int u,v,w;
        cin >>u>>v>>w;
        a[u].push_back(edges(u,v,w));
    }
    cin >> s>>t;
}
void dijkstra() {
    for (int i=1; i<=n; i++) {
        f[i]=1e9;
    }
    f[s]=0;
    while (true) {
        int u=-1,fu=1e9;
        for (int i=1; i<=n; i++) {
            if (f[i]<fu&&!visited[i]) {
                fu=f[i];
                u=i;
            }
        }
        if (u==-1) {
            cout << "-1";//khong co duong di ngan nhat giua hai dinh
            break;
        }
        if (u==t){
            break;
        }
        visited[u]=true;
        for (edges e: a[u]) {
            f[e.v]=min(f[e.v],fu+e.weight);
        }
    }
    cout <<f[t];
}
int main(){
    //freopen("E://abc.txt","r",stdin);
    input();
    dijkstra();
}
