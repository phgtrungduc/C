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
void connectedcomp(int num) {
    if (visited[num]==false) {

        visited[num] = true;
        for (int i=0; i<adj[num].size(); i++) {
            if (visited[adj[num][i]]==false) connectedcomp(adj[num][i]);
        }
    }
}
int main() {
    freopen("E:\\abc.txt","r",stdin);
    input();
    int number =0;
    for (int i=1;i<=n;i++){
        if (visited[i]==false){
            connectedcomp(i);
            number++;
        }
    }
    cout << endl<<number;
}
