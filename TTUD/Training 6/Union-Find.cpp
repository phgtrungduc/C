#include<bits/stdc++.h>
using namespace std;
struct union_find {
    vector<int>parent;
    union_find(int n) {
        parent = vector<int>(n);
        for (int i=1; i<=n; i++) {
            parent[i]=i;
        }
    }
    int find(int x){
        if (parent[x]==x) {
            return x;
        }
        else {
            parent[x]= find(parent[x]);
            return parent[x];
        }
    }
    void unite(int x,int y){
        parent[find(x)] = find(y);
    }
} x(6);
int main(){
    x.unite(1,4);
    x.unite(3,5);
    x.unite(3,6);
    x.unite(4,6);
    x.unite(2,4);
    for(int i=1;i<=6;i++){
        cout << x.find(i)<<" ";
    }
}
