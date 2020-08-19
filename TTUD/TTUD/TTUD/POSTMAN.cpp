#include <iostream>
#include<vector>
using namespace std;
using namespace std;
long long S = 0;
long long k;
int n;
void swap(long long* a, long long* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(long long* arr, long long* m, int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] > pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			swap(&m[i], &m[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	swap(&m[i + 1], &m[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(long long* arr, long long* m, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, m, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, m, low, pi - 1);
		quickSort(arr, m, pi + 1, high);
	}
}

void findDistance(long long* x, long long* m, int start, int end) {
	if (start < end) {
		for (int i = start; i < end; i++) {
			if (m[i] > k) {
				/*cout << m[i] / k << endl;*/
				S = S + 2 * abs(x[i]) * (m[i] / k);
				m[i] = m[i] % k;
				if (m[i] != 0)i--;
				/*cout << "S: " << S << endl;*/
			}
			else if (m[i] == k) {
				S += 2 * (abs(x[i]));
			}
			else {
				S += 2 * abs(x[i]);
				long long temp = m[i];
				while (i < end - 1 && temp <= k) {
					i++;
					temp += m[i];
				}
				/*cout << "i: " << i << endl;
				cout << "temp: " << temp<<endl;*/
				if (temp > k) {
					temp -= m[i];
					m[i] -= k - temp;
					if (m[i] != 0) i--;
				}
			}
		}
	}
}

int main() {
	cin >> n >> k;
	long long* x = new long long[n];
	long long* m = new long long[n];
	int duong = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		cin >> m[i];
		if (x[i] > 0) duong++;
	}
	quickSort(x, m, 0, n - 1);
	if (duong != n) {
		int j = 0;
		for (int i = duong; i < duong + (n - duong) / 2; i++) {
			swap(&x[i], &x[n - j - 1]);
			swap(&m[i], &m[n - j - 1]);
			j++;
		}
		findDistance(x, m, duong, n);
	}
	findDistance(x, m, 0, duong);
	/*for (int i = 0; i < n; i++) {
		cout << "xong" << endl;
		cout << x[i] << " " << m[i] << endl;
	}*/
	cout << S;
}