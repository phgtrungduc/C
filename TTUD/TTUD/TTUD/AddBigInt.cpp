#include<iostream>
#include<string>
using namespace std;

string add(string a, string b)
{
    string res = "";
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    int carry = 0;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        int temp = (a[i] - 48) + (b[i] - 48) + carry; //char - 48 de chuyen kieu ngam dinh sang int, carry la nho tu phep cong truoc
        carry = temp / 10;
        temp = temp % 10;
        res = (char)(temp + 48) + res;
    }
    if (carry > 0) res = "1" + res;
    return res;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << add(a, b) << endl;
    return 0;
}