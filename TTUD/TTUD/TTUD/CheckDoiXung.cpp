#include<iostream>
#include<deque>
using namespace std;
bool checkPan(string a) {
	int n = a.length();
	return true;
}
void decToBinary(int n)
{
    // array to store binary number 
    int binaryNum[1000];

    // counter for binary array 
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array 
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}
int main() {
	int x = (1 <<3) | (1<<2) ;
    cout << (x & (1 << 2));
    decToBinary(x);
}