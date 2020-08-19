#include<iostream>
#include<algorithm>
using namespace std;
int n;
int s[200007];
int t[200007];
int best = 0;
bool isFind = false;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> t[i];
	}
}

void solution(){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
            if (i!=j&&t[i] < s[j]) {
                isFind = true;
                int temp = (t[i] - s[i]) + (t[j]-s[j]);
                best = max(best, temp);
            }
		}
	}
}

void print() {
    for (int i = 0; i < n; i++) {
        cout << s[i] <<"--"<< t[i];
        cout << endl;
    }
}
int main() {
    /*freopen("E:\\abc.txt","r",stdin);*/
	input();
    solution();
    if (isFind == false) {
        cout << -1;
    }
    else {
        cout << best;
    }
}