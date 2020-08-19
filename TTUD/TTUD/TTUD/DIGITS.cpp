#include<iostream>
#include <string>
using namespace std;
#define size 11
bool visited[size];
int x[size];
int n = 0;
int ans = 0;

void input() {
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		visited[i] = false;
	}
}

int chartoint(char a) {
	return a - '0';
}
int compute() {
	return (x[1] * 100 + x[2] * 10 + x[3]) -
		(x[7] * 100 +62) +
		(x[4] * 1000 + x[5] * 100 + x[6] * 10 + x[3]);
}

void solution() {
	for (int i = 1; i <= 7; i++) {
		cout << x[i] << "  ";
	}
	cout << endl;
	cout << compute() << endl;
}
void TRY(int num) {
	for (int i = 1; i <= 9; i++) {
		if (visited[i] == false) {
			x[num] = i;
			visited[i] = true;
			if (num == 7) {
				
				if (compute() == n) {
					ans++;
				}
			}
			else {
				TRY(num + 1);
			}
			visited[i] = false;
		}
		
	}
}


int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
	TRY(1);
	cout << ans;
}
