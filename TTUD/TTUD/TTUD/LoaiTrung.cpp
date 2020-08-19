#include<iostream>
#include<vector>
using namespace std;
void eliminate(vector <int>a,int l,int r,int m) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i=0;i<n1;i++){
		L[i] = a[i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = a[m+1+i];
	}
	for (int i = 0; i < n1; i++) {
		cout << L[i] << "  ";
	}
	cout << endl;
	for (int i = 0; i < n2; i++) {
		cout << R[i] << "  ";
	}
	int index = l;
	int left = 0;
	int right = 0;
	while (left < n1 && right < n2) {
		if ()
	}
}
void split(vector<int>a , int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		split(a, l, m);
		split(a, m + 1, r);
		eliminate(a,l,r,m);
	}
}
int main() {
	vector <int>a;
	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[j] == a[i]) {
				n--;
				for (int k = j; k < n; k++) {
					a[k] = a[k + 1];
				}
				j--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}*/
	eliminate(a,0,n-1,(n-1)/2);
}