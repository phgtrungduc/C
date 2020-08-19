#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long a;
	long long S=0;
	while (n--) {
		cin >> a;
		S += a;
	}
	long long b = 1000000007;
	cout << S% b;
	return 0;
}