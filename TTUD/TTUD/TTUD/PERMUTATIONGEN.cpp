#include<iostream>
using namespace std;
int n;
int x[10007];
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
}
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void solution() {
	for (int i = 1; i <= n; i++) {
		cout << x[i] << " ";
	}
}
bool compute() {
	int temp = -1;
	if (n == 1) return false;
	for (int i = n; i > 1; i--) {
		if (x[i] > x[i - 1]) {
			temp = i - 1;
			break;
		}
	}
	
	if (temp == -1) return false;
	else {
		int vitri = -1;
		for (int i = temp + 1; i <= n; i++) {
			if (x[i] > x[temp] ) {
				vitri = i;
			}
		}
		if (vitri!=-1) swap(x[temp], x[vitri]);
		for (int i = n; i > temp + 1; i--) {
			swap(x[i], x[i - 1]);
		}
		return true;
	}

}
int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
	if (compute() == false) {
		cout << -1;
	}
	else {
		solution();
	}
}