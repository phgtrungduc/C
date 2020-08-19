#include<iostream>
using namespace std;
int n;
int M = 26;
string p;
string fibo[101];
int dp[101];
void input() {
	while (scanf("%d", &n) != EOF) {
		cin >> p;
	}
	fibo[]
}
int count(string a,string b) {
	for (int i = 0; i < a.size() - b.size(); i++* {
		int matched = 1;
			for (int j = 0; j < b.size(); j++) {
				if (a[j + 1] != b[j]) {
					matched = 0;
						break;
				}
				ret+=matched;
			}
	}
	return ret;
}
long long calc(int n, string p) {
	if (n < M) return count();
}