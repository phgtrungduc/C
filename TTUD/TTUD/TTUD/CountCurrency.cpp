#include <iostream>
#include <map>
using namespace std;
int main()
{
    map <int, int> m;
    int n1, n2;
    cout << "Nhap so gia tri: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> n2;
        m[n2] ++;
    }
    for (int i = 0; i<100; i++) {
        if (m.count(i) != 0) {
            cout << i << ": " << m[i]<<endl;
        }
    }
}