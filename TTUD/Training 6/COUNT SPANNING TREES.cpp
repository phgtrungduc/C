#include<bits/stdc++.h>
using namespace std;
vector<int>a[26];
int n,m;

bool visited[26];
int res[26];

struct edge {
    int u,v;
    edge(int _u,int _v) {
        u=_u;
        v = _v;
    }
};
vector<edge> edges;
struct union_find {
    int parent[100];
    union_find(int n) {

        for (int i=1; i<=n; i++) {
            parent[i]=i;
        }
    }
    int find(int x) {
        if (parent[x]==x) {
            return x;
        } else {
            parent[x]= find(parent[x]);
            return parent[x];
        }
    }
    void unite(int x,int y) {
        parent[find(x)] = find(y);
    }
};

bool solution(){
    union_find uf = union_find(n);
    for (int i=1;i<=n-1;i++){
        edge temp = edges[res[i]];
        if (uf.find(temp.u)==uf.find(temp.v)) return false;
        else uf.unite(temp.u,temp.v);
    }
    return true;
}

void input() {
    cin >>n>>m;
    for (int i=0; i<m; i++) {
        int one,two;
        cin >> one>>two;
        edges.push_back(edge(one,two));
    }
    res[0]=-1;
    memset(visited,false,sizeof(visited));
}
int dem =0;
void back_track(int num) {
    for (int i=res[num-1]+1;i<m;i++){
        if (!visited[i]){
            visited[i]=true;
            res[num]=i;
            if (num==n-1){
                if (solution()) dem++;
            }
            else {
                back_track(num+1);
            }
            visited[i]=false;
        }
    }
}
int main() {
    //freopen("E://abc.txt","r",stdin);
    input();
    back_track(1);
    cout << dem;
}
