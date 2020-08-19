#include <iostream>
#include <stack>
#include<vector>
using namespace std;

unsigned long long findMaxSq(unsigned long long *a,int n) {
	stack <long long> s;
	unsigned long long top;
	unsigned long long distance;
	unsigned long long S;
	unsigned long long max=0;
	int i = 0;
	while (i < n) {
		if (s.empty() || a[s.top()] <= a[i]) {
			s.push(i++);
		}
		else {
			top = s.top();
			s.pop();
			distance = s.empty()?i:(i - s.top() - 1);//Neu hang doi rong tuc la thang vua push ra se la thang nho nhat trong so
			S = a[top] * distance;//tat ca nhung thang da push de them vao thang a[i]
			if (S > max) max = S;//vi the nen khi rong chieu ngang se nhan gia tri la i
		}
		/*cout << "i: " << i;
		cout <<" "<< max << endl;*/
	}
	while (!s.empty()) {
		top = s.top();
		s.pop();
		distance = s.empty() ? i : (i - s.top() - 1);
		S = a[top] * distance;
		if (S>max) max = S;
	}
	return max;
}



int main() {
	int n=-1;
	unsigned long long size = 0;
	unsigned long long *a;
	vector<unsigned long long> max;
	do {
		cin >> n;
		if (n == 0) break;
		a = new unsigned long long[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		max.push_back(findMaxSq(a,n));
		size++;
	} while (n != 0);
	for (int i = 0; i < size; i++) {
		cout << max[i] << endl;
	}
	return 0;
}
