#include <iostream>
using namespace std;
#include <vector>
int countPhucTap(vector <int>a,int size) {
	int count = 1;
	for (int i = 1; i < size; i++) {
		if (a[i] != a[i - 1]) {
			count++;
		}
	}
	return count;
}

int main() {
	int n;
	vector <int> t;
	vector <int > p, c;
	cin >>n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		t.push_back(temp);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> temp;
		p.push_back(temp);
		cin >> temp;
		c.push_back(temp);
	}
	vector <int> count;
	int dem = countPhucTap(t,n);
	/*cout << endl << "Do phuc tap ban dau: " << dem<<endl;*/
	for (int i = 0; i < q; i++) {
		temp = t[p[i] - 1];
		t[p[i] - 1] = c[i];
		/*cout << endl << "temp: " << temp << endl;
		cout << endl << "p: " << p[i] - 1 << endl;
		cout << endl << "t: " << t[p[i] - 1] << endl;*/
		if (p[i]-1==0) {
			if (temp == t[p[i]]) {
				if (t[p[i] - 1] != t[p[i]]) dem++;
			}
			else if (temp != t[p[i]]) {
				if (t[p[i]] == t[p[i] - 1]) dem--;
			}
		}
		else if (p[i] - 1 == n - 1) {
			if (temp != t[n - 2]) {
				if (t[n - 1] == t[n - 2]) dem--;
			}
			else {
				if (t[n - 1] != t[n - 2]) dem++;
			}
		}
		else if  (p[i] - 2 >= 0 && t[p[i]] == t[p[i] - 2]) {
			if (temp != t[p[i]]) {
				if (t[p[i] - 1] == t[p[i]]) dem -= 2;
			}
			else {
				if (t[p[i] - 1] != t[p[i]]) dem += 2;
			}
		}
		else if (p[i] - 2 >= 0 && t[p[i]] != t[p[i] - 2]) {
			if (temp == t[p[i]]||temp==t[p[i]-2]) {
				if (t[p[i] - 1] != t[p[i]]&&t[p[i]-2]!= t[p[i] - 1]) dem += 1;
			}
			else {
				if (t[p[i]-1] == t[p[i]] || t[p[i] - 1] == t[p[i] - 2]) dem -=1;
			}
		}
		count.push_back(dem);
	}
	for (int i = 0; i < q; i++) {
		cout << count[i]<<endl;
	}
}