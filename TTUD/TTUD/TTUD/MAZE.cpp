#include<iostream>
#include<vector>
using namespace std;
int N, M;
int c[901][901];
int startx, starty;
int ans = 0;
pair <int, int> way[100000];
int dem = 0;
int best = 999;
bool visited[901][901];
//1=up,2=right,3=down,4=left
void input() {
	cin >> N >> M>>startx>>starty;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> c[i][j];
		}
	}
}
bool availble(int x, int y) {
	if (x > M || x<1 || y>M || y < 1) return false;
	return true;
}
bool goal(int x, int y) {
	if (x == 1 || y == 1) return true;
	else return false;
}

bool check(int x,int y,int i) {
	if (i == 1) {
		if (visited[x - 1][y] == true) return false;
		if (availble(x - 1, y) == false) return false;
		if (c[x - 1][y] == 1)return false;
	}
	else if (i == 2) {
		if (visited[x][y+1] == true) return false;
		if (availble(x , y+1) == false) return false;
		if (c[x][y+1] == 1)return false;
	}
	else if (i == 3) {
		if (visited[x + 1][y] == true) return false;
		if (availble(x +1, y) == false) return false;
		if (c[x + 1][y] == 1)return false;
	}
	else if (i == 4) {
		if (visited[x][y-1] == true) return false;
		if (availble(x , y-1) == false) return false;
		if (c[x ][y-1] == 1)return false;
	}
	return true;
} 

void solution() {
	for (int i = 1; i <= 20; i++) {
		cout<< way[i].first<<"-"<<way[i].second<<"   ";
	}
	cout << endl;
}

void TRY(int x,int y) {
	for (int i = 1; i <= 4; i++) {
		if (check(x, y, i)) {
			int nextx = 0;
			int nexty = 0;
			if (i == 1) {
				nextx = x - 1;
				nexty = y;
			}
			else if (i == 2) {
				nextx = x ;
				nexty = y+1;
			}
			else if (i == 3) {
				nextx = x + 1;
				nexty = y;
			}
			else {
				nextx = x;
				nexty = y-1;
			}
			visited[x][y] = true;
			dem++;

			/*cout <<x<<"  "<<y<<" "<< dem << endl;
			cout << nextx << "  " << nexty << " " <<endl;
			cout << goal(nextx, nexty) << endl;*/
			way[dem] = make_pair(x,y);
			if (goal(nextx, nexty)) {
				dem++;
				if (best > dem-1) best = dem-1;
			}
			else {
				if (dem < best) TRY(nextx,nexty);
			}
			visited[x][y] = false;
			dem--;
		}
	}
}


int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
	TRY(startx,starty);
	cout << best;
}