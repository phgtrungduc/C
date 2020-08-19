#include<iostream>;
#include<algorithm>;
using namespace std;
int x[100002];
int n;
int result[100002];
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i <= n; i++) {
        result[i] = -1;
    }
}

int max_sum(int num) {
    if (result[num] != -1) {
        return result[num];
    }
    int temp = 1;
    for (int i = 0; i < num; i++) {
        if (x[num] > x[i]) {
            temp = max(temp,(1 + max_sum(i)));
        }
    }
    result[num] = temp;
    return temp;
}
void compute() {
    for (int i = 0; i < n; i++) {
        max_sum(i);
    }
}
void calc() {
    for (int i=1; i<=n; i++) {
        result[i]=1;
        for (int j=i-1; j>=1; j--) {
            if (x[i]>x[j]) {
                result[i]=max (result[i],result[j]+1);
            }
        }
    }
}
int main() {
    //freopen("E:\\abc.txt", "r", stdin);
    input();
    calc();
    int temp = 0;
    for (int i = 1; i <= n; i++) {
        if (result[i] > temp) {
            temp = result[i];
        }
    }
    cout << temp;

}
