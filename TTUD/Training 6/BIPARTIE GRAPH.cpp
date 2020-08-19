#include<bits/stdc++.h>
using namespace std;
vector <int> adj[100005];
int n,m;
int color[100005];
bool isbipartie=true;
void input() {
    cin >> n>>m;
    int one,two;
    for (int i=0; i<m; i++) {
        cin >> one >> two;
        adj[one].push_back(two);
        adj[two].push_back(one);
    }
    memset(color,-1,sizeof(color));
}
void isBipartie(int num) {
    //cout << "num: "<<num<<endl;
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
int main() {
    //freopen("E:\\abc.txt","r",stdin);
    input();
    int number =0;
    for (int i=1; i<=n; i++) {
        if (color[i]==-1) {
            color[i]=0;
            isBipartie(i);
        }
    }
//    for (int i=1;i<=n;i++){
//        cout << color[i]<<endl;
//    }
    cout << isbipartie;
}

