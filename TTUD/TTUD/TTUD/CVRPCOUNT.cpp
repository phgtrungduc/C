#include<iostream>
using namespace std;
#define size 11

int n; //so luong khach hang
int K;//so luong xe tai
int Q; // capacity xe tai
int d[size]; //d[i] la luong hang cua khach hang thu i
int load[size];//load[i] la trong tai hien tai cua xe i
int x[size]; //x[i] diem tiep theo cua chang i 
int y[size];//y[i] la diem den dau tien cua xe thu i
bool visited[size];//ghi nhan dinh da tham chua
int segment;
int ans = 0;
void input()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        visited[i] = false;
        load[i] = 0;
    }
    y[0] = 0;
}

void solution_Y() {
    cout << "Tuyen dau: ";
    for (int i = 1; i <= K; i++) {
        cout << y[i] << "  ";
    }
    cout << endl;
    cout << "tai trong: ";
    for (int i = 1; i <= K; i++) {
        cout << load[i] << "  ";
    }
    cout << endl;
}

void solution() {
    for (int i = 1; i <= K; i++) {
        cout << "Tuyen duong cua xe thu: " << i << ": ";
        for (int j = y[i]; j != 0; j = x[j]) {
            cout << j << "  ";
        }
        cout << endl;
    }
    cout << "ket thuc" << endl;
    cout << endl;
    cout << endl;
}

bool check(int v, int num) {
    if (v > 0 && visited[v] == true) return false;
    if (v > 0 && load[num] + d[v] > Q) return false;
    return true;
}

void TRY(int v, int num) {
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            if (num == K) {
                x[v] = i;
                segment++;
                if (segment == K + n) {
                    ans++;
                }
                segment--;
            }
            else {
                x[v] = i;
                segment++;
                TRY(y[num + 1], num + 1);
                segment--;
            }

        }
        else {
            if (check(i, num)) {
                x[v] = i;
                segment++;
                load[num] += d[i];
                visited[i] = true;
                TRY(i, num);
                segment--;
                load[num] -= d[i];
                visited[i] = false;
            }
        }
    }
}

void TRY_Y(int num) {
    for (int i = y[num - 1] + 1; i <= n; i++) {
        if (visited[i] == false) {
            y[num] = i;
            load[num] += d[i];
            visited[i] = true;
            if (num == K) {
                segment = K;
                TRY(y[1], 1);
            }
            else {
                TRY_Y(num + 1);
            }
            visited[i] = false;
            load[num] -= d[i];
        }
    }
}





int main() {
    /*freopen("E:\\abc.txt", "r", stdin);*/
    input();
    TRY_Y(1);
    cout << ans;
}