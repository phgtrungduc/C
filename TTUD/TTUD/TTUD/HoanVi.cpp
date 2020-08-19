#include <iostream>
#include<vector>
using namespace std;
void cogang(int *a, int k, int n, bool *check) {
	for (int i = 0; i <n; i++) {
		if (check[i] == false) {
			a[k] = i;
			check[i] = true;
			if (k == n-1) {
				for (int i = 0; i < n; i++) {
					cout << a[i];
				}
				cout << endl;
				
			}
			else {
				cogang(a, k + 1, n, check);
			}
		}
		else {
			
			continue;
		}
		check[i] = false;
	}
}
int main() {
	int* a = new int[100];
	bool* check = new bool[100];
	for (int i = 0; i < 5; i++) {
		check[i] = false;
	}
	cogang(a, 0, 5, check);
}