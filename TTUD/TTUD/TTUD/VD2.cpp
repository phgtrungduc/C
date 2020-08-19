#include<iostream>
#include<algorithm>
using namespace std;
int n;
int x[1000];
int result[1000];
bool comp[1000];
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
}

int max_sub(int num) {
	if (comp[num] == true) return result[num];
	int res = 1;
	for (int i = 0; i < num; i++) {
		if (x[i] < x[num]) {
			res = max(res,1+max_sub(num-1));
		}
	}
	result[num] = res;
	comp[num] = true;
	return res;
}


int main() {
	freopen("E:\\abc.txt", "r", stdin);
	input();
	cout << max_sub(n-1);
}