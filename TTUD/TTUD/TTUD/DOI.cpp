#include<iostream>
#include<algorithm>
using namespace std;
int n;
int x[1000000];
int doi = 0, thunglung = 0;
int temp = 0;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
}
void calcutlale() {
	for (int i = 1; i < n-1; i++) {
		temp = x[i];
		int cao1 = 0, cao2 = 0;
		for (int j = i - 1; j >= 0; j--){
			if (x[j] < temp) {
				cao1++;
				temp = x[j];
			}
			else break;
		}
		temp = x[i];
		for (int j = i+1; j < n; j++) {
			if (x[j] < temp) {
				cao2++;
				temp = x[j];
			}
			else break;
		}
		int mintemp = min(cao1,cao2);
		doi = max(doi,mintemp);
	}
	for (int i = 1; i < n-1; i++) {
		temp = x[i];
		int cao1 = 0, cao2 = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (x[j] > temp) {
				cao1++;
				temp = x[j];
			}
			else break;
		}
		temp = x[i];
		for (int j = i + 1; j < n; j++) {
			if (x[j] > temp) {
				cao2++;
				temp = x[j];
			}
			else break;
		}
		thunglung = max(thunglung, min(cao1, cao2));
	}
}
int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
	calcutlale();
	cout << doi << " " << thunglung;
}