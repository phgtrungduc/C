#include<iostream>
#include<algorithm>
using namespace std;
int N, D, T;
int a[1001],t[1001];
int result[1001];
int time[1001];
void input() {
	cin >> N >> D >> T;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < N; i++) {
		result[i] = -1;
		time[i] = 0;
	}
}

int cal(int num) {
	if (result[num] != -1) {
		return result[num];
	}
	int rtemp = a[num];
	for (int i = num - D; i < num; i++) {
		if (time[num] + t[i] <= T) {
			rtemp = max(rtemp,result[i]+a[]);
		}
	}
}

int main() {
	freopen("E:\\abc.txt", "r", stdin);
	input();
}