#include<bits/stdc++.h>
using namespace std;
int n,m,k;

bool visited[35];
int res[35];
vector<edge>a[35];
struct edge {
    int u,v;
    edge(int _u,int _v) {
        u=_u;
        v = _v;
    }
};
vector<edge> edges;

int dem=0;
bool check=true;
void DFS(int u){
    dem ++;
    visited[u]=true;
    for (edge v:a[u]){
        if (!visited[v.v]) DFS(v.v);
        else {
            if (dem!=k) check=false;
        }
    }
}



bool solution() {
    dem = 0;
    check =true;
    for (int i=1;i<=n;i++){
        a[i].clear();
    }
    for (int i=1; i<=k; i++) {
        edge temp = edges[res[i]];
        a[temp.u].push_back(temp.v);
        a[temp.v].push_back(temp.v);
    }


}

void input() {
    cin >>n>>m>>k;
    for (int i=0; i<m; i++) {
        int one,two;
        cin >> one>>two;
        edges.push_back(edge(one,two));
    }
    res[0]=-1;
    memset(visited,false,sizeof(visited));
}

void back_track(int num) {
    for (int i=res[num-1]+1; i<m; i++) {
        if (!visited[i]) {
            visited[i]=true;
            res[num]=i;
            if (num==k) {
                solution();
            } else {
                back_track(num+1);
            }
            visited[i]=false;
        }
    }
}
int main() {
    freopen("E://abc.txt","r",stdin);
    input();
    back_track(1);
}
