#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
int N;
vector<int> A[MAX_N];// A[v][i] is the i^th adjacent node to v
vector<int> c[MAX_N];// c[v][i] is the weight of the i^th adjacent edge to v
int d[MAX_N];// d[v] is the distance from the source node to v in BFS
int p[MAX_N];// p[v] is the parent of v in BFSEXERCISE

void input() {
    iostream::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N-1; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        A[v].push_back(u);
        A[u].push_back(v);
        c[v].push_back(w);
        c[u].push_back(w);
    }
}
void BFS(int u) {
    queue<int> Q;
    d[u] = 0;
    Q.push(u);
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for(int i = 0; i < A[v].size(); i++) {
            int x = A[v][i];
            if(d[x] > -1) {
                if(p[v] != x) cout << "FALSE" << endl;
                continue;
            }
            int w = c[v][i];
            Q.push(x);
            d[x] = d[v] + w;
            p[x] = v;
        }
    }
}
int findMax() {
    int max_d = -1;
    int u = -1;
    for(int v = 1; v <= N; v++) {
        if(max_d < d[v]) {
            max_d = d[v];
            u = v;
        }
    }
    return u;
}
void init() {
    for(int v = 1; v <= N; v++) {
        d[v] = -1;
        p[v] = -1;
    }
}
void solve() {
    init();
    BFS(1);
    int u = findMax();
    init();
    BFS(u);
    u = findMax();
    cout << d[u];
}
int main() {
    freopen("E://abc.txt","r",stdin);
    input();
    solve();
}
