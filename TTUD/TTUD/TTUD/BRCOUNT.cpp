#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s;
int dem = 0;
int n;
int vitri[10001];
bool visited[10001];
int ans = 0;
void input() {
	getline(cin, s);
	n = s.length();
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			vitri[dem] = i;
			dem++;
		}
	}
}
bool check(string a, int n) {
	stack <char> st;
	for (int i = 0; i < n; i++) {
		if (st.empty()) {
			if (a[i] == ')') return false;
			else st.push(a[i]);
		}
		else {
			if (a[i] == '(') st.push(a[i]);
			else st.pop();
		}
	}
	if (st.empty()) return true;
	else return false;
}

//bool moNgoac(char s) {
//	if (s == '(' || s == '{' || s == '[') return true;
//	else return false;
//}
//bool dongNgoac(char s) {
//	if (s == ')' || s == '}' || s == ']') return true;
//	else return false;
//}
//bool sameType(char s, char t) {
//	if (s == '(' && t == ')') return true;
//	if (s == '[' && t == ']') return true;
//	if (s == '{' && t == '}') return true;
//	return false;
//}
//int check(string a, int n) {
//	stack <char> st;
//	for (int i = 0; i < n; i++) {
//		if (st.empty()) {
//			if (dongNgoac(a[i])) return 0;
//			else st.push(a[i]);
//		}
//		else {
//			if (moNgoac(a[i])) st.push(a[i]);
//			else {
//				if (sameType(st.top(), a[i])) {
//					st.pop();
//				}
//				else return 0;
//			}
//		}
//	}
//	if (st.empty()) return 1;
//	else return 0;
//}
void TRY(int num) {
	for (int i = 0; i <= 1; i++) {
		int temp = vitri[num];
		if (i == 0) {
			s[temp] = '(';
		}
		else {
			s[temp] = ')';
		}
		if (num == dem - 1) {
			if (check(s, n) == true) ans++;
		}
		else {
			TRY(num + 1);
		}
	}
}
int main() {
	freopen("E:\\abc.txt", "r", stdin);
	input();
	TRY(0);
	cout << ans;
}