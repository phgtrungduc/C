#include<bits/stdc++.h>
using namespace std;
vector <int> adj[100005];
int n,m,T;
int color[100005];
bool isbipartie=true;

void isBipartie(int num) {
    for (int i=0; i<adj[num].size(); i++) {
        int v = adj[num][i];
        if (color[v]==-1) {
            if (color[num]==1) color[v] = 0;
            else color[v]=1;
            isBipartie(adj[num][i]);
        } else if (color[v]==color[num]) {
            isbipartie = false;
        }
    }
}


void input() {
    cin >>T;
    for (int i=0; i<T; i++) {
        isbipartie=true;
        cin >> n>>m;
        for (int j=1; j<=n; j++) {
            color[j]=-1;
            adj[j].clear();
        }
        for (int i=0; i<m; i++) {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i=1; i<=n; i++) {
            isBipartie(i);
        }
        if (!isbipartie) {
            cout << "Scenario #"<<i+1<<":"<<endl;
            cout << "Suspicious bugs found!";
        } else {
            cout << "Scenario #"<<i+1<<":"<<endl;
            cout << "No suspicious bugs found!";
        }
        cout <<endl;
    }
}

int main() {
    //freopen("E:\\abc.txt","r",stdin);
    iostream::sync_with_stdio(false);
    cin.tie(0);
    input();
}


