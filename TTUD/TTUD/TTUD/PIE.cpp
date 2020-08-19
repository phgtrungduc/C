#include <iostream>
#include <algorithm>
using namespace std;
#define N 5000
int x[N];
int K;
int n;
int dem = 0;
int count =0 ;
void input() {
    cin >> n >> K;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
}


int binarySearch(int arr[], int l, int r, int x) {
    if (l<=r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x)
            return 1+binarySearch(arr,l,mid-1,x)+ binarySearch(arr, mid+1, r, x);
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}


void solution() {
    for (int i = 0; i < n - 2; i++) {
        long long s = x[i];
        for (int j = i + 1; j < n - 1; j++) {
            s += x[j];
            if (binarySearch(x, j + 1, n - 1, K - s) != -1) {
                dem++;
            }
            s -= x[j];
        }
    }
    cout << dem << endl;
}


int main() {
    freopen("E:\\abc.txt", "r", stdin);
    input();

    sort(x + 1, x + n);
    cout << binarySearch(x, 0, n - 1, 3);
}