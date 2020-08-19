#include<iostream>
using namespace std;
int F[100]; 
int fibo1(int n) {
	if (n <= 2) return n;
	else {
		return fibo1(n - 1) + fibo1(n-2);
	}
}
int fibo2(int n) {
	if (n <= 2) {
		F[n] = n;
	}
	else {
		if (F[n] == 0) {
			F[n] = fibo2(n - 1) + fibo2(n-2);
		}
	}
	return F[n];
}
int main() {
	cout << fibo1(5);
	cout << fibo2(5);
}