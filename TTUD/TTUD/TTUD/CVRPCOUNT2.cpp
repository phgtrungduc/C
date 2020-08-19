#include <stdio.h>
#include<conio.h>
#include<iostream>
#define MAX 50
using namespace std;
int n, K, Q;
int d[MAX];
int x[MAX]; // x[i] is the next point of i (i = 1,...,n), x[i] \in
// {0,1,...,n}
int y[MAX];// y[k] is the start point of route k
int load[MAX];
int visited[MAX];// visited[i] = 1 means that client point i has beenvisited
int segments;// number of segments accumulated
int nbRoutes;
int ans; // records number of solutions
void solution() {
	ans++;
	for (int k = 1; k <= K; k++) {
		int s = y[k];
		printf("route[%d]: 0 ", k);
		for (int v = s; v != 0; v = x[v]) {
			printf("%d ", v);
		}
		printf("0\n");
	}
	printf("---------------------------\n");
}


int checkX(int v, int k) {
	if (v > 0 && visited[v]) return 0;
	if (load[k] + d[v] > Q) return 0;
	return 1;
}
void input() {
	scanf("%d%d%d", &n, &K, &Q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
	}
	d[0] = 0;
}


void TRY_X(int s, int k) {
	for (int v = 0; v <= n; v++) {
		if (checkX(v, k)) {
			x[s] = v;
			visited[v] = 1; load[k] += d[v]; segments++;
			if (v > 0) TRY_X(v, k);
			else {
				if (k == K) {
					if (segments == n + nbRoutes) solution();
				}
				else TRY_X(y[k + 1], k + 1);
			}
			segments--; load[k] -= d[v]; visited[v] = 0;
		}
	}
}


int checkY(int v, int k) {//v la vi tri den, k la xay dung phuong an cho xe thu k
	if (v == 0) return 1;
	if (load[k] + d[v] > Q) return 0;
	return !visited[v];
}


void TRY_Y(int k) {
	for (int v = y[k - 1] + 1; v <= n; v++) {// 0 < y[1] < y[2] < . . . . < y[K]
		if (checkY(v, k)) {
			y[k] = v;
			segments += 1;
			visited[v] = 1; load[k] += d[v];
			if (k < K) {
				TRY_Y(k + 1);
			}
			else {
				nbRoutes = segments;
				TRY_X(y[1], 1);// du bo y[1],...,y[K], bat dau duyet cho diem tiep
				// theo cua y[1]
			}
			load[k] -= d[v]; visited[v] = 0;
			segments -= 1;
		}
	}
}

void solve() {
		for (int v = 1; v <= n; v++) visited[v] = 0;
		y[0] = 0;
		ans = 0;
		TRY_Y(1);
		cout << ans;
	}

	int main() {
		input();
		solve();
	}