#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool visited[100005];
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
        a[v].push_back(edges(v,u,w));
    }
}
vector <edges> prim() {
    vector <edges>res;
    vector<int>bestW(n+1,1e9),bestA(n+1,-1);
    bestW[1]=0;//bat dau tu dinh 1
    while(res.size()<n-1) {
        int u=-1,v=-1,w=1e9;
        for (int i=1; i<=n; i++) {
            if (visited[i]==false&&bestW[i]<w) { //duyet qua tat ca cac dinh chua duoc chon, chon ra dinh cos khoang cach ngn nhat den cay khung
                u= bestA[i];//u la dinh gan no nhat tren cay khug
                v = i;
                w = bestW[i];//w la khoang cach ngan nhat tu cay khung den v
            }
        }

        if (v==-1) return res;
        visited[v]=true;
        for (edges e:a[v]) {
            if (bestW[e.v]>e.weight) {
                bestA[e.v] = e.u;
                bestW[e.v]=e.weight;

            }
        }
        if (u!=-1)res.push_back(edges(u,v,w));
    }
    return res;
}
int main() {
    //freopen("E://abc.txt","r",stdin);
    input();

    vector<edges>res = prim();
    int S =0;
    if (res.size()<n-1){
        cout << "-1";
    }
    else {
        for (int i=0;i<res.size();i++){
            S +=res[i].weight;
        }
        cout << S;
    }
}
