#include<bits/stdc++.h>
using namespace std;
vector<int>a[100005];
int n,m,Time=0,low[100005],num[100005];
bool visited[100005];
bool isbridge[100005][100005];
void input(){
    cin >>n>>m;
    for (int i=0; i<m; i++) {
        int u,v;
        cin >>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(num,-1,sizeof(num));
    memset(visited,false,sizeof(visited));
}
void find_bridge(int u,int p){//u la dinh dang xet, v la dinh truoc no
    low[u]=num[u]=++Time;
    for (int v:a[u]){
        if (v!=p){
            if(num[v]!=-1){//đã xét khi num = -1 cạnh u v sẽ là cạnh ngược và chắc chắn thuộc 1 chu trình, nếu khác -1 chứng tỏ chưa duyệt qua
                    low[u]=min(low[u],num[v]);//low đỉnh cha cập nhật bằng num đỉnh con để thõa mãn low là chỉ số đỉnh nhỏ nhất cạnh ngược đến được
            }
            else {//nếu đỉnh v chưa xét qua, cạnh u v là cạnh xuôi, dfs tiếp tục theo cạnh xuôi
                find_bridge(v,u);
                low[u]=min(low[u],low[v]);//lan truyền low nếu có bất kì thằng con cháu nào thuộc 1 cạnh ngược
                if (low[v]>=num[v]) {//uv la cầu
                    isbridge[u][v] = true;
                };
            }
        }
    }
}
int dfs(int u){//đếm số đỉnh trong 1 thành phần liên thông
    visited[u]=true;
    int dem =1;
    for (int v:a[u]){
            if (isbridge[u][v]&&!visited[v]){
                dem += dfs(v);
            }
    }
    return dem;
}
int main(){
    freopen("E://abc.txt","r",stdin);
    input();
    for (int i=1;i<=n;i++){
        if (num[i]==-1){
            find_bridge(i,-1);
        }
    }
    long long ans =0;
    for (int i=1;i<=n;i++){
        if(!visited[i]){
            int tmp = dfs(i);
            ans += tmp*(tmp-1)/2-(tmp-1);
        }
    }
    cout << ans;
}
