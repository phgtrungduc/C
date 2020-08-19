#include<iostream>;
using namespace std;
int n, m, M;
int x[20001];
int dem = 0;
void input() {
	cin >> n >> m >> M;
	for (int i = 0; i < n;i++) {
		cin >> x[i];
	}
}
void compute() {
	for (int i = 0; i < n; i++) {
		int S = 0;
		for (int j = i; j < n; j++) {
			S += x[j];
			if (S >= m && S <= M) dem++;
		}
		
	}
}
int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
	compute();
	cout << dem;
}