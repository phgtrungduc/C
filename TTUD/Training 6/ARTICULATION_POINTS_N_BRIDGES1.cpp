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
void findBridge(){

}

int main() {
    freopen("E:\\abc.txt","r",stdin);
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

