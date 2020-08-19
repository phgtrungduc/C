#include<iostream>
#include <string> 
using namespace std;
int n;
string x;
string temp;
void input(){
    cin >> n;
    getline(cin,temp);
    getline(cin,x);
}
bool solve(string &x) {
    int vitri = -1;
    for (int i = n-1; i >= 0; i--) {
        if (x[i] == '0') {
            vitri = i;
            break;
        }
    }
    if (vitri == -1) return false;
    else {
        x[vitri] = '1';
        for (int i = vitri+1; i < n; i++) {
            x[i] = '0';
        }
        return true;
    }
}
int main() {
    input();
    bool check = solve(x);
    if (check == false) {
        cout << -1;
    }
    else {
        cout << x;
    }
}