#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>ans[4];
int a[400];
int num = 0;
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < 0)num++;
    }
}
void compute() {
    if (num == 1) {
        for (int i = 1; i <= n; i++) {
            if (a[i] < 0)ans[0].push_back(a[i]);
            else if (a[i] == 0)ans[2].push_back(a[i]);
            else ans[1].push_back(a[i]);
        }
    }
    else if (num % 2 == 0) {
        int k = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < 0 && k == 0) {
                ans[0].push_back(a[i]);
                k++;
            }
            else if (a[i] < 0 && k == 1) {
                ans[2].push_back(a[i]);
                k++;
            }
            else if (a[i] == 0) ans[2].push_back(a[i]);
            else ans[1].push_back(a[i]);
        }
    }
    else {
        int k = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < 0 && k == 0) {
                ans[0].push_back(a[i]);
                k++;
            }
            else if (a[i] == 0)ans[2].push_back(a[i]);
            else ans[1].push_back(a[i]);
        }
    }
}

void solution() {
    for (int i = 0; i < 3; i++) {
        cout << ans[i].size()<<" ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout <<"\n";
    }
}
int main(){
    input();
    compute();
    solution();
    
}