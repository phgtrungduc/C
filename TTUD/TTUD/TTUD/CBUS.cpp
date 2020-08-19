#include <iostream>
using namespace std;
#define MAX_N 12
int n;// so khach
int k;// so cho tren bus cho hanh khach
int x[2 * MAX_N + 1];// bieu dien phuong an lo trinh X[1], X[2], . . . X[2N]
int q=0;// so khach thuc su dang co tren xe ung voi phuong an bo phan hien tai
bool appear[2 * MAX_N + 1];
int c[23][23];
int ans = 99999;
int c_min=999;
int scout = 0;
void input(){
	cin >> n >> k;
	for (int i = 0; i <= 2*n; i++) {
		for (int j = 0; j <= 2*n;j++) {
			cin >> c[i][j];
			if (i != j) c_min = c_min < c[i][j] ? c_min : c[i][j];
		}
	}
	for (int v = 1; v <= 2 * n; v++) {
		appear[v] = false;
	}
	x[0] = 0;
}


bool check(int i) {  //kiem tra voi diem toi thu v,diem thu k tren lo trinh
	if (appear[i]) return false;
	if (i <= n) {//don hanh khach thu v 
		if (q >= k) return false;//neu don them hanh khach nhung so luong hanh khach tren xe da day thi tu choi nhan
	}
	else {//them 1 diem xuong vao lo trinh
		if (!appear[i - n]) return false;//neu hanh khach chua duoc don thi cung chua duoc tra
	}
	return true;
}

void solution() {
	for (int i = 1; i <= 2 * n;i++) {
		cout << x[i] << "  ";
	}
}
int count() {
	int temp = 0;
	for (int i = 1; i <= 2 * n; i++) {
		if (i == 2 * n) {
			temp += c[x[i - 1]][x[i]];
			temp += c[x[2 * n]][0];
		}
		else {
			temp += c[x[i - 1]][x[i]];
		}
	}
	return temp;
}
void TRY(int num) {// thu gia tri cho x[k]
	for (int i = 1; i <= 2 * n; i++) {
		if (check(i)) {
			x[num] = i;
			appear[i] = true;
			if (i <= n) q++; else q--;
			scout += c[x[num - 1]][x[num]];
			if (num == 2 * n) {
				int temp = count();
				if (temp < ans) ans = temp;
 			}
			else {
				int bound = scout + (2*n-num)*c_min;
				if (bound  < ans) TRY(num + 1);
			}
			appear[i] = false;
			if (i <= n) q--; else q++;
			scout -= c[x[num - 1]][x[num]];
		}
	}
}
int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
	TRY(1);
	cout << ans;
}