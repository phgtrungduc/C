#include<iostream>;
#include<algorithm>;
using namespace std;
int n;
int x[1000007];
int result[1000007];
bool comp[1000007];
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		comp[i] = false;
		cin >> x[i];
	}
	result[0] = max(0,x[0]);
	comp[0] = true;
}

void solution() {
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}
int max_sub(int num) {
	if (comp[num] == true) {
		return result[num];
	}
	int temp = -999999;
	temp = max(x[num],x[num]+max_sub(num-1));
	result[num] = temp;
	comp[num] = true;
	return temp;
}

int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
	max_sub(n - 1);
	int temp = -999999;
	for (int i = 0; i < n; i++) {
		temp = max(temp,result[i]);
	}
	cout << temp;
}