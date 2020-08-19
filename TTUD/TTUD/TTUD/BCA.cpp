#include<iostream>
using namespace std;
int m, n; // m la so giao vien, n la so mon hoc
int can[31][31];// can[i] la cac mon giao vien i co the day
int conflict[31][31];//conflict[i][j] = 1 neu mon hoc i va j xung dot
int numConflict;
int solve[31];//solve[i] la giao vien se day mon hoc thu i 
int ans = 0;
int ansmax = 999999999;
int load[31];
void input() {
	cin >> m >> n;
	int temp;
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 30; j++) {
			conflict[i][j] = 0;
			can[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> temp;
		for (int j = 1; j <= temp; j++) {
			int temp2;
			cin >> temp2;
			can[i][temp2] = 1;   
		}
	}
	cin >> numConflict;
	int tempa, tempb;

	for (int i = 1; i <= numConflict; i++) {
		cin >> tempa >> tempb;
		conflict[tempa][tempb]  = conflict[tempa][tempb] =1;
	}
	for (int i = 1; i <= n; i++) {
		load[i] = 0;
	}
}


bool check(int sub, int teacher) {
	if (can[teacher][sub]==0) return false;
	
	for (int i = 1; i <sub; i++) {
		if (solve[i] == teacher && conflict[i][sub]==1) return false;
		if (solve[i] == teacher && conflict[sub][i] == 1) return false;
	}
	return true;
}

int numAns() {
	int temp=0;
	for (int i = 1; i <= m; i++) {
		if (temp < load[i]) temp = load[i];
	}
	return temp;
}

void solSub(int num) {
	for (int i = 1; i <= m; i++) {
		
		if (check(num, i)) {
			solve[num] = i;
			load[i]++;
			if (num == n) {
				ans++;
				int temp = numAns();
				if (ansmax > temp) ansmax = temp;
			}
			else {
				if (load[i] < ansmax) solSub(num + 1);
			}
			load[i]--;
		}	
	}
}

int main() {
	//freopen("E:\\abc.txt","r",stdin);
	input();
	solSub(1);
	if (ans == 0) cout << -1;
	else {
		cout << ansmax;
	}
}