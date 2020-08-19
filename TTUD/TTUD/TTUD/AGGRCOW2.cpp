#include<iostream>
#include<algorithm>
using namespace std;
long long n, c;
long long x[100007];
long long T;
long long low = 0, high;

void compute() {
	while (low < high - 1) {
		long long mid = (low + high) / 2;
		long long count = 1;
		long long now = x[1];
		for (long long i = 2; i <= n; i++) {
			if (x[i] - now >= mid) {
				count++;
				now = x[i];
			}
		}
		if (count >= c) low = mid;
		else high = mid;
	}
}

void input() {
	cin >> T;
	while (T--) {
		low = 0;
		cin >> n >> c;
		for (long long i = 1; i <= n; i++) {
			cin >> x[i];
			if (i > 1) {
				high = max(high, x[i+1]-x[i]);
			}
		}
		sort(x + 1, x + n+1);
		compute();
		cout << low << endl;
	}

}


int main() {
	freopen("E:\\abc.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
}