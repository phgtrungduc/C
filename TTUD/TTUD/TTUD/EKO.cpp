#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int a[1000000+7];
int S = 0;
int cmax = 0;
int low = 0;
int high = 0;
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cmax = max(cmax,a[i]);
	}
	high = cmax;
}
long long count_wood(int number) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > number) sum += a[i] - number;
	}
	return sum;
}
void compute() {
	while (low < high-1) {
		
		int mid = (low + high) / 2;
		long long number = count_wood(mid);
		cout << number << "--";
		cout << low << "--" << high << endl;
		if (number >= m) low = mid ;
		else high = mid;
		
	}
}
int main() {
	freopen("e:\\abc.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	compute();
	cout << low <<"  "<< high;
	/*cout << compute();*/
}