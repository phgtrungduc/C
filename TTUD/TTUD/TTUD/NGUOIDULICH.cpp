#include<iostream>
using namespace std;

int n, m;
unsigned long long c[400 + 1][400 + 1];
int minmin = 9999999;
unsigned long long S = 0;
bool diqua[400 + 1];
unsigned long long canduoi = 99999999999999;
unsigned long long cmin = 999999999999999;

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		diqua[i] = false;
		for (int j = 1; j <= n; j++) {
			c[i][j] = 9999999999;

		}
	}
	diqua[1] = true;
	int i, j;
	for (int k = 0; k < m; k++) {
		cin >> i >> j;
		cin >> c[i][j];
		cmin = c[i][j] < cmin ? c[i][j] : cmin;
	}
}
void findMin(int number, int pre) {
	for (int i = 1; i <= n; i++) {
		if (!diqua[i]) {
			S += c[pre][i];
			diqua[i] = true;
			canduoi = (n - number) * cmin + S;
			if (number == n) {
				unsigned long long temp = S + c[i][1];
				minmin = temp < minmin ? temp : minmin;
				/*cout <<"S = "<< minmin<<endl;*/
			}
			else {
				if (canduoi < minmin) findMin(number + 1, i);
			}
			diqua[i] = false;
			S -= c[pre][i];
		}
	}
}

int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/

	input();
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << c[i][j] << "  ";
		}
		cout << endl;
	}*/
	findMin(2, 1);
	cout << minmin;
}