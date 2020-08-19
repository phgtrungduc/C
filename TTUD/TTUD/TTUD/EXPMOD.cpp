#include<iostream>
using namespace std;

long long powmod(long long a, long long b) {
	long long temp=1;
	if (b == 1) return a;
	else {
		long long temp = powmod(a, b / 2);
		temp = temp * temp;
		if (b % 2) temp = temp * a;
		return temp;
	}
	

}

int main() {
	long long a, b;
	cin >> a>> b;
	long long chia = 1000000007;
	long long du = a % chia;
	long long temp = du;
	for (int i = 0; i < b - 1; i++) {
		temp = (temp * du) % chia;
	}
	cout << temp;
}