#include<iostream>
#include<math.h>
using namespace std;
int main() {
	long long a, b;
	cin >> a >> b;
	long long c = (pow(10, 9) + 7);
	cout << (a + b) % c;
}