#include<iostream>;
using namespace std;
int* x;
int* displeased;
int n;
void input() {
	cin >> n;
	x = new int[n + 1];
	displeased = new int[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
}
void calculate() {
	for (int i = 0; i < n; i++) {
		int vitri = -1;
		for (int j = i + 1; j < n; j++) {
			if (x[j] < x[i]) {
				vitri = j;
			}
		}
		if (vitri == -1) displeased[i] = -1;
		else {
			displeased[i] = vitri - i - 1;
		}
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		cout << displeased[i] << " ";
	}
}

int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
	calculate();
	solution();
}