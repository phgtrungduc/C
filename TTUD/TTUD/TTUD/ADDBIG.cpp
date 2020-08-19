#include<iostream>
#include<string>
using namespace std;
void addBig(string a,string b) {
	if (a.length() == 1) {

	}
}
int main() {
	string a,b;
	getline(cin,a);
	getline(cin,b);
	while (a.length() < b.length()) a = "0" + a;
	while (b.length() < a.length()) b = "0" + b;
	cout << a <<endl<<b;
}