#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
	
	int T=0, L, C;
	cin >> T;
	vector <pair<int, int>> a;
	vector<pair <int, int>> b;
	int **vitri= new int*[2000];
	for (int i = 0; i < T;i++) {
		a.clear();
		b.clear();
		
		cin >> L>> C;
		int temp;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < C; j++) {
				cin >> temp;
				if (temp != 0) a.push_back(make_pair(i,j));
			}
		}
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < C; j++) {
				cin >> temp;
				if (temp != 0) b.push_back(make_pair(i, j));
			}
		}
		for (int i = 0; i < 2000; i++) {
			vitri[i] = new int[2000];
		}
		for (int i = 0; i < 2000; i++) {
			for (int j = 0; j < 2000; j++) {
				vitri[i][j] = 0;
			}
		}
		int max = 0;
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j< b.size(); j++) {
				pair<int, int > temp = make_pair(a[i].first - b[j].first, a[i].second - b[j].second);
				int temp1 = temp.first;
				int temp2 = temp.second;
				vitri[temp1 + 1000][temp2 + 1000] ++;
				if (vitri[temp1 + 1000][temp2 + 1000] > max) max = vitri[temp1 + 1000][temp2 + 1000];
			}
		}
		cout << max<<endl;
	}
	
}
