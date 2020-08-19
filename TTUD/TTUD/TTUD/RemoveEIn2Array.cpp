#include <iostream>
#include<vector>
using namespace std;

bool find(vector <int >a, int value) {
	for (int i= 0; i < a.size(); i++) {
		if (a[i] == value) return true;
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	int count1 = 0, count2 = 0;
	int temp;
	vector <int >a;
	vector<int >b;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		b.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		if (find(b, a[i]) == false) count1++;
	}
	for (int i = 0; i < m; i++) {
		if (find(a, b[i]) == false) count2++;
	}
	cout << (count1 > count2 ? count1 : count2);
}