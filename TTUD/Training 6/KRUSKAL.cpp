#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool visited[100005];

struct union_find {
    vector<int>parent;
    union_find(int n) {
        parent = vector<int>(n+1);
        for (int i=1; i<=n; i++) {
            parent[i]=i;
        }
    }
    int find(int x){
        if (parent[x]==x) {
            return x;
        }
        else {
            parent[x]= find(parent[x]);
            return parent[x];
        }
    }
    void unite(int x,int y){
        parent[find(x)] = find(y);
    }
};





struct edges {
    int u,v,weight;
    edges(int _u,int _v,int w) {
        u = _u;
        v= _v;
        weight= w;
    }
};
vector <edges>a;
void input() {
    cin >>n>>m>>k;
    for (int i=0; i<m; i++) {
        int u,v,w;
        cin >>u>>v>>w;
        a.push_back(edges(u,v,w));

    }
}
bool cmp(edges a1,edges a2) {
    return a1.weight< a2.weight;

}
vector<edges> kruskal() {
    sort(a.begin(),a.end(),cmp);
    union_find uf= union_find(n);
    vector<edges> res;
    for (int i=0;i<m;i++){
        int u= a[i].u,v=a[i].v;
            if (uf.find(u)!=uf.find(v)){
                uf.unite(u,v);
                res.push_back(a[i]);
            }
    }
    return res;
}
int main() {
    freopen("E://abc.txt","r",stdin);
    input();
    vector<edges>res =kruskal();
    for (int i=0;i<res.size();i++){
        cout << res[i].u<<"  "<<res[i].v<<"  "<<res[i].weight<<endl;
    }
    cout << "done";
}
