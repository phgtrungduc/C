#include<bits/stdc++.h>
using namespace std;
vector<int>a[100001];
int n,m,Time=0,low[100001],num[100001];
bool check[100001];//1 đỉnh có check = true nếu đỉnh này đã thuộc 1 thành phần liên thông mạnh
int LTM =0;
stack<int>st;
void input() {
    cin >>n>>m;
    for (int i=0; i<m; i++) {
        int u,v;
        cin >>u>>v;
        a[u].push_back(v);
    }
    memset(num,-1,sizeof(num));
    memset(low,-1,sizeof(low));
    memset(check,false,sizeof(check));
}
void tarjan(int u,int p) { //u la dinh dang xet, v la dinh truoc no
    st.push(u);
    low[u]=num[u]=++Time;
    for (int v:a[u]) {
        if (v!=p) {
            if(num[v]==-1) {
                tarjan(v,u);
                low[u]=min(low[u],low[v]);

            } else if (!check[v]){//loại bỏ các trường hợp đã thuộc các thành phần liên thông mạnh trước đó rồi
                low[u]=min(low[u],num[v]);
            }
        }
    }
    //kết thúc duyệt một thành phần liên thông bắt đầu từ u
    if (low[u]==num[u]) { //u là đỉnh bắt đàu của 1 thành phần liên thông mạnh
        LTM++;
        int v;
        do {
            v = st.top();
            check[v]=true;
            st.pop();
        } while(v!=u);
    }
}
int main() {
    freopen("E://abc.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    for (int i=1; i<=n; i++) {
        if (num[i]==-1) {
            tarjan(i,-1);
        }
    }
    cout << LTM;
}
