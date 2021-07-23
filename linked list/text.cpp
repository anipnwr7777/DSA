#include<bits/stdc++.h>
using namespace std;
const int n = 1;
const int m = 4;

void cal_sum(int arr[n][m]) {
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < m ; j++) {
			arr[i][j] = i + 3;
		}
	}
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < m ; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int arr[1][4] = {{1, 2, 3, 4}};
	cal_sum(arr);

	
	return 0;
}