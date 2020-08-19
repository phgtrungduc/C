#include<bits/stdc++.h>
using namespace std;
vector <int> a[100005];
bool visited[100005];
int n,m;
void input() {
    cin >> n>>m;
    int one,two;
    for (int i=0; i<m; i++) {
        cin >> one >> two;
        a[one].push_back(two);
        a[two].push_back(one);
    }
    memset(visited,false,sizeof(visited));
}

void DFS(int start) {
    stack<int>st;
    st.push(start);
    while(!st.empty()) {
        int u= st.top();

        cout <<"Ke: " <<u<<"  ";
        st.pop();
        for (int v:a[u]) { //duyet tat a cac dinh ke cua u
            if (!visited[v]) {
                visited[v]=true;
                st.push(v);
            }
        }
        cout << endl;
    }
}

int main() {
    freopen("E://abc.txt","r",stdin);
    input();
//    for (int i=1;i<=n;i++){
//        cout <<"Ke: "<<i<<"   ";
//        for (int j=0;j<a[i].size();j++){
//
//            cout << a[i][j]<<"  ";
//        }
//        cout <<endl;
//    }
    DFS(1);
}

