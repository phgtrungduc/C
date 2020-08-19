#include<bits/stdc++.h>
using namespace std;
vector <int> adj[100005];     //đồ thị vô hướng, không có trọng số
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

vector <int> adj[100005];     //đồ thị có hướng, không có trọng số
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

struct edges {      //đồ thị có trọng số nhưng chỉ quan tâm đến trọng số cạnh ví dụ trong kruskal
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



struct edges {    //lưu trữ cạnh đồ thị có trọng số cơ bản
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
