#include<iostream>;
#include<stack>;
using namespace std;
stack <int> s1,s2;
int query;
int type, number;

void enQ(int number){
	s1.push(number);
}

void deQ() {
	if (s1.empty() && s2.empty()) return;
	if (s2.empty()) {
		while (s1.empty() == false) {
			int x = s1.top();
			s2.push(x);
			s1.pop();
		}
	}
	s2.pop();
}

int front() {
	if (s2.empty()) {
		while (s1.empty() == false) {
			int x = s1.top();
			s2.push(x);
			s1.pop();
		}
	}
	int x = s2.top();
	return x;
}
void input() {
	cin >> query;
	for (int i = 0; i < query; i++) {
		cin >> type;
		if (type == 1) {
			cin >> number;
			enQ(number);
		}
		else if (type == 2) deQ();
		else {
			cout << front()<<endl;
		}
	}
}
int main() {
	input();
}