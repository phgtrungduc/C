#include<iostream>
#include<algorithm>
using namespace std;
int n, c;
int x[100007];
int result[100007];
bool visited[100007];
int cmax=0;
int T;

int solution() {
	int temp = 999999999;
	/*for (int i = 1; i <= c; i++) {
		cout << result[i] << "--";
	}
	cout << endl;*/
	for (int i = 1; i < c; i++) {
		temp = min(temp, result[i + 1] - result[i]);
	}
	return temp;
}
void TRY(int num) {
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			result[num] = x[i];
			visited[i] = true;
			if (num == c) {
				cmax = max(cmax, solution());
			}
			else {
				if (num == 1 || (result[num] - result[num - 1] > cmax))TRY(num + 1);
			}
			visited[i] = false;
		}
	}
}

void input() {
	cin >> T;
	while (T--) {
		cin >> n >> c;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		cmax = 0;
		for (int i = 1; i <= c; i++) {
			visited[i] = false;
		}
		TRY(1);
		cout << cmax << endl;
	}
	
}

int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
}