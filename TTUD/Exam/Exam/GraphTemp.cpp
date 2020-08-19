#include<bits/stdc++.h>
using namespace std;
vector <int> adj[100005];
int n,m;
bool visited[100005];
void input() {
    cin >> n>>m;
    int one,two;
    for (int i=0; i<m; i++) {
        cin >> one >> two;
        adj[one].push_back(two);
        adj[two].push_back(one);
    }
    memset(visited,false,sizeof(visited));
}

vector <int> adj[100005];
int n,m;
bool visited[100005];
void input() {
    cin >> n>>m;
    int one,two;
    for (int i=0; i<m; i++) {
        cin >> one >> two;
        adj[one].push_back(two);
    }
    memset(visited,false,sizeof(visited));
}

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
    cin >>n>>m;
    for (int i=0; i<m; i++) {
        int u,v,w;
        cin >>u>>v>>w;
        a.push_back(edges(u,v,w));

    }
}



struct edges {
    int u,v,weight;
    edges(int _u,int _v,int w) {
        u = _u;
        v= _v;
        weight= w;
    }
};

vector <edges>a[25];
void input() {
    cin >> n>>m>>k;
    for (int i=0; i<m; i++) {
        int u,v,w;
        cin >>u>>v>>w;
        a[u].push_back(edges(u,v,w));
        a[v].push_back(edges(v,u,w));
    }
}
int main() {
	freopen("E://abc.txt", "r", stdin);
	input();
}

