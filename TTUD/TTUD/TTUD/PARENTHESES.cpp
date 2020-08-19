#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool moNgoac(char s) {
	if (s == '(' || s == '{' || s == '[') return true;
	else return false;
}
bool dongNgoac(char s) {
	if (s == ')' || s == '}' || s == ']') return true;
	else return false;
}
bool sameType(char s,char t) {
	if (s == '(' && t == ')') return true;
	if (s == '[' && t == ']') return true;
	if (s == '{' && t == '}') return true;
	return false;
}
int check(string a, int n) {
	stack <char> st;
	for (int i = 0; i < n; i++) {
		if (st.empty()) {
			if (dongNgoac(a[i])) return 0;
			else st.push(a[i]);
		}
		else {
			if (moNgoac(a[i])) st.push(a[i]);
			else {
				if (sameType(st.top(), a[i])) {
					st.pop();
				}
				else return 0;
			}
		}
	}
	if (st.empty()) return 1;
	else return 0;
}
int main() {
	int n;
	cin >> n;
	string a;
	int* kq = new int[n];
	int i = 0;
	string temp;
	getline(cin,temp);
	while (i<n) {
		getline(cin,a);
		kq[i] = check(a,a.length());
		i++;
	}
	for (int i = 0; i < n; i++) {
		cout << kq[i] << endl;
	}
}