#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[107];
int x[107];
int res[107];
int dem =0;
void input() {
    cin >>n>>m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        x[i] = m/a[i];
    }
}

int calc(){
    int S=0;
    for (int i=1;i<=n;i++){
        S+=res[i]*a[i];
    }
    return S;
}
void solution(){
    for (int i=1;i<=n;i++){
        cout << res[i]<<"  ";
    }
    cout << endl;
}

void TRY(int num){
    for (int i=1;i<=x[num];i++){
        res[num]=i;
        if (num==n){
            int S =calc();
            if (S == m) {
                dem++;
            }
        }
        else TRY(num+1);
    }
}

int main() {
    //freopen("E://abc.txt", "r", stdin);
    input();
    TRY(1);
    cout << dem;
}
