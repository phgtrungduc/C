#include<bits/stdc++.h>
using namespace std;
string S;
int k,n;
int res[100005];
bool visited[100005];
string result="";
string ans="" ;

void input() {
    getline(cin,S);
    cin >>k;
    n = S.length();
    res[0]=-1;
}

void solution(){
    for (int i=1;i<=k;i++){
        result.append(1,S[res[i]]);
    }
}

void TRY(int num) {
    for (int i=res[num-1]+1; i<n; i++) {
        if (!visited[i]) {
            res[num]=i;
            visited[i]=true;
            if (num==k){
                solution();
                if (result>ans) ans = result;
                result = "";
            }
            else {
                TRY(num+1);
            }
            visited[i]=false;
        }
    }
}

int main() {
	//freopen("E://Bai2.txt", "r", stdin);
	iostream::sync_with_stdio(false);
    cin.tie(0);
	input();
	TRY(1);
	cout << ans;
}


