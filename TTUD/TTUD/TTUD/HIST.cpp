//#include <iostream>
//#include <vector>
//#include<map>
//using namespace std;
//int minValue(vector <int> a,int start, int end) {
//	int min = INT32_MAX;
//	for (int i = start; i <= end; i++) {
//		if (a[i] < min) min = a[i];
//	}
//	return min;
//}
//int main() {
//	int n;
//	int size = 0;
//	int temp;
//	map <int, vector <int >>a;
//	do {
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> temp;
//			a[size].push_back(temp);
//		}
//		size++;
//	} while (n != 0);
//	size--;
//	int* max = new int[size];
//	for (int i = 0; i < size; i++) {
//		int start;
//		int maxScope = a[i][0];
//		/*cout << "max vao: " << maxScope<<endl;*/
//		if (a[i][0] == 0) {
//			start = 1;
//		}
//		else {
//			start = 0;
//		}
//		for (int j = 1; j < a[i].size(); j++) {
//			if (a[i][j - 1] == 0) {
//				if (a[i][j] > maxScope) maxScope = a[i][j];
//			}
//			else {
//				if (a[i][j] == 0) {
//					start = j+1;
//				}
//				else {
//					for (int k = j; k >= start; k--) {
//						///*cout << "than vong lap: "<<k<<endl;*/
//						//long long temp1 = (long long)minValue(a[i],k,j)*(long long)(abs(k - j)+1);
//						///*cout << temp1<<endl;*/
//						//if (temp1 > maxScope) maxScope = temp1;
//						
//					}
//				}
//			}
//		}
//		max[i] = maxScope;
//		/*cout << "Ket thuc lan thu: " << i + 1 << endl;*/
//	}
//	for (int i = 0; i < size; i++) {
//		cout << max[i] << endl;
//	}
//}
