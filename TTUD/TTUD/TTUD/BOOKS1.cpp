#include<iostream>
#include <algorithm> 
using namespace std;
int T;//number of case
int N, K;
int p[501];
void input(){
    cin >> T;
    for (int v = 0; v < T; v++) {
        cin >> N >> K;
        for (int i = 1; i <= K; i++) {
            cin >> p[i];
        }
    }
}

int main() {
    /*freopen("E:\\abc.txt", "r", stdin);*/
    input();
}