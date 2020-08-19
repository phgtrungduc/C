//cài đặt dijikstra bằng vòng lặp thông thường mất O(n2) còn với hàng đợi ưu tiên là O(m.log(n)) nhưng chỉ cài đặt bằng
//hàng đợi ưu tiên với đồ thị thưa
// ở bài toán này xây dựng 1 đồ thị mới với các đỉnh giữ nguyên, trọng số của 1 cạnh bằng chi phí nhỏ nhất đi từ 2 đỉnh từ đồ thị ban đầu

#include<bits/stdc++.h>
using namespace std;
int n,m;
//fi lưu trữ chi phí đường đi ngắn nhất đến đỉnh i
int c[5001],d[5001],dist[5001][5001],f[5001];//c[i] lưu chi phí của tuyến xe bus thứ i và d[i] khoảng cách xa nhất đi được từ i
vector<int>a[5001];//lưu trữ cạnh đồ thị
bool visited[10000];
void dijkstra() {
    for (int i=1; i<=n; i++) {
        f[i]=1e9;
    }
    f[1]=0;//di từ đỉnh 1, tìm đường đi ngắn nhất
    while (true) {
        int u=-1,fu=1e9;
        for (int i=1; i<=n; i++) { //tim dinh co khoang cach ngan nhat den dinh dang xet
            if (f[i]<fu&&!visited[i]) {
                fu=f[i];
                u=i;
            }
        }
        if (u==-1) break;
        visited[u]=true;
        for (int v=1; v<=n; v++) {
            if (dist[u][v]<=d[u]) f[v]=min(f[v],fu+c[u]);
        }
    }
    cout <<f[n];
}

void input() {
    cin >>n>>m;
    for(int i=1; i<=n; i++) {
        cin >> c[i]>>d[i];
    }
    for (int i=0; i<m; i++) {
        int u,v;
        cin >>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dist[i][j]=1e9;

        }
    }
    //bfs tinh dist[u][v]
    for (int i=1; i<=n; i++) {
        queue<pair<int,int>>qu;
        qu.push(make_pair(i,0));//1 pair se gom v la ten dinh va thanh phan thu 2 la khoang cach tu dinh dang xet toi v
        dist[i][i]=0;
        while(!qu.empty()) {
            int u= qu.front().first;//ten dinh dang xet
            int du = qu.front().second;//khoang cach tu dinh dang xet den dinh ban dau i
            qu.pop();
            for (auto v:a[u]) { //duyet tat a cac dinh ke cua u
                if (dist[i][v]>du+1) {
                    dist[i][v]=du+1;
                    qu.push(make_pair(v,dist[i][v]));//(dinh v,khoang cach tu dinh dang xet i den dinh v)
                }
            }
        }
    }

    dijkstra();
}
int main() {
//    freopen("E://abc.txt","r",stdin);
    input();
}
