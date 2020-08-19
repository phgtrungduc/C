#include<iostream>;
using namespace std;
int T, n;
long long x[1001], y[1001];
long long temp[1001];
bool visited[1001];
long long best = 99999999999999;
long long Stemp = 0;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

int partition(long long arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++;  
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(long long arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int partition2(long long arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] > pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}
void quickSort2(long long arr[], int low, int high) {
	if (low < high) {
		int pi = partition2(arr, low, high);
		quickSort2(arr, low, pi - 1);
		quickSort2(arr, pi + 1, high);
	}
}













void result(int i) {
	cout << "Case #" << i << ": " << best << endl;
}
long long calculate() {
	long long S = 0;
	for (int i = 0; i < n; i++) {
		S += x[i] * y[i];
	}
	return S;
}


void input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> x[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> y[j];
		}
		quickSort(x, 0, n - 1);
		quickSort2(y, 0, n - 1);
		best = calculate();
		result(i+1);
	}
}



int main() {
	/*freopen("E:\\abc.txt", "r", stdin);*/
	input();
}