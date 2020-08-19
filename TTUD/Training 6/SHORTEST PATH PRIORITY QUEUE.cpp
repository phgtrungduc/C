#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
int f[100005];
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
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;


struct cmp {
    bool operator() (pair <int,int>a,pair<int,int> b) {
        return a.first>b.first;
    }
};

void input() {
    cin >> n>>m;
    for (int i=0; i<m; i++) {
        int u,v,w;
        cin >>u>>v>>w;
        a[u].push_back(edges(u,v,w));
    }
    cin >>s>>t;
    memset(visited,false,sizeof(visited));
    for (int i=1;i<=n;i++){
        f[i]=1e9;
    }
}

void dijkstra() {
    f[s]=0;
    pq.push(make_pair(f[s],s));
    while(!pq.empty()) {
        pair<int,int> onTop = pq.top();
        int u = onTop.second;
        cout << "u: "<<u<<endl;
        pq.pop();
        for (int i=0; i<a[u].size(); i++) {
            int v =a[u][i].v;
            int w =a[u][i].weight;
            if (f[v]>f[u]+w) {
                f[v] = f[u]+w;
                pq.push(make_pair(f[v],v));
            }
        }
    }
    cout << f[t];
}
int main() {
    freopen("E://abc.txt","r",stdin);
    input();
    dijkstra();
}
