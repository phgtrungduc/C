#include<iostream>
using namespace std;
#define MAX 17
int n, m;
int c[MAX];
int A[MAX][MAX];
bool visited[MAX];
int x[MAX];
int load[6];
int best=999999;
void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		visited[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		};
	}
	for (int i = 1; i <= 5; i++) {
		load[i] = 0;
	}
}
int answer() {
	int temp = 0;
	for (int i = 1; i <= m; i++) {
		if (temp < load[i]) temp = load[i];
	}
	return temp;
}
void solution() {
	for (int i = 1; i <= n; i++) {
		cout << x[i] << "  ";
	}
	cout << endl;
	for (int i = 1; i <= m; i++) {
		cout << load[i] << "  ";
	}
	cout << endl;
}

bool check(int sub,int semester) {
	for (int i = 1; i < sub; i++) {
		if (A[sub][i] == 1 && semester >= x[i]) return false;
	}
	return true;
}

void TRY(int num) {
	for (int i = 1; i <= m; i++) {
		if (check(num,i)) {
			x[num] = i;
			load[i] +=c[num] ;
			if (num == n) {
				int temp = answer();
				best = best < temp ? best : temp;
			}
			else {
				if (load[i]<best) TRY(num+1);
			}
			load[i] -= c[num];
		}
	}
}


int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
	TRY(1);
	cout << best;
}