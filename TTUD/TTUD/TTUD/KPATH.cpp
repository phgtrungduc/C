#include<iostream>
using namespace std;

int n, k,m;
int way[31][31];
int ans = 0;
bool visited[31];
int x[12];
void input() {
	cin >> n >> k >> m;
	int first, second;
	for (int i = 0; i < m; i++) {
		scanf("%d",&first); 
		scanf("%d", &second);
		way[first][second] = way[second][first]=1;
	}
}
bool check(int num, int i) {
	if (num == 1) return true;
	else if (visited[i] == true) return false;
	else {
		if (way[x[num - 1]][i] == 1 || way[i][x[num - 1]] == 1) return true;
	}
	return false;
}
void TRY(int num) {
	for (int i = 1; i <= n; i++) {
		if (check(num, i)) {
			x[num] = i;
			visited[i] = true;
			if (num == k+1) {
				ans++;
			}
			else {
				TRY(num+1);
			}
			visited[i] = false;
		}
	}
}

int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
	TRY(1);
	printf("%d",ans/2);
}