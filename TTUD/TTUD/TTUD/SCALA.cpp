#include<iostream>;
using namespace std;
int T, n;
long long x[1001], y[1001];
long long temp[1001];
bool visited[1001];
long long best = 99999999999999;
long long Stemp = 0;

void solution() {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << temp[i] << " ";
	}
}
void result(int i) {
	cout << "Case #" << i << ": " << best<<endl;
}
long long calculate() {
	int S = 0;
	for (int i = 0; i < n; i++) {
		S += x[i] * temp[i];
	}
	return S;
}
void a() {
	cout << "temp: ";
	for (int i = 0; i < n; i++) {
		cout << temp[i] << " ";
	}
	cout << endl;
}
long long bound(int num) {
	long long S = 0;
	for (int i = 0; i <= num; i++) {
		S += x[i] * temp[i];
	}
	return S;
}
void TRY(int num) {
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			temp[num] = y[i];
			int S = bound(num);
			if (num == n - 1) {
				long long temp1 = calculate();
				best = best < temp1 ? best : temp1;
			}
			else {
				 TRY(num + 1);
			}
			visited[i] = false;
		}
	}
}
void input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> x[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> y[j];
		}
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}
		best = 999999999998999;
		TRY(0);
		result(i+1);
	}
}



int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
}