#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool visited[25];
struct edges {
    int u,v,weight;
    edges(int _u,int _v,int w) {
        u = _u;
        v= _v;
        weight= w;
    }
};

vector <edges>a[26];
void input() {
    cin >> n>>m>>k;
    for (int i=0; i<m; i++) {
        int u,v,w;
        cin >>u>>v>>w;
        a[u].push_back(edges(u,v,w));
        a[v].push_back(edges(v,u,w));
    }
}
vector <edges> prim(int start) {
    vector <edges>res;
    vector<int>bestW(n+1,1e9),bestA(n+1,-1);
    memset(visited,false,sizeof(visited));
    bestW[start]=0;//bat dau tu dinh start
    while(res.size()<k) {
        int u=-1,v=-1,w=1e9;
        for (int i=1; i<=n; i++) {
            if (visited[i]==false&&bestW[i]<w) { //duyet qua tat ca cac dinh chua duoc chon, chon ra dinh cos khoang cach ngn nhat den cay khung
                u= bestA[i];//u la dinh gan no nhat tren cay khug
                v = i;
                w = bestW[i];//w la khoangcach ngan nhat tu cay khung den v
            }
        }
        if (v==-1) return res;
        visited[v]=true;
        for (int i=0; i<a[v].size(); i++) {
            edges temp =a[v][i];
            if (bestW[temp.v]>temp.weight) {
                bestA[temp.v] = v;
                bestW[temp.v]=temp.weight;
            }
        }
        if (u!=-1)res.push_back(edges(u,v,w));
    }
    return res;
}
int main() {
    //freopen("E://abc.txt","r",stdin);
    input();
    bool check = false;
    long long ans =1e9;
    for (int i=1; i<=n; i++) {
        vector<edges>res = prim(i);
        long long s=0;
        if (res.size()==k){
            check = true;
            for (int i=0; i<res.size(); i++) {
                s+=res[i].weight;
                //cout << res[i].u<<"  "<<res[i].v<<"  "<<res[i].weight<<endl;
            }
            ans = ans >s?s:ans;
        }
    }
    if (check) cout << ans;
    else cout << "-1";
}

