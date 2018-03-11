#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmpFunc(int i, int j) {
	return i > j;
}

void miniMaxSum(vector <int> arr) {
	// Complete this function
	sort(arr.begin(), arr.end(), cmpFunc);
	// Ordered the vector, so now the minimum sum is sum of the four last array elements
	unsigned long int min = 0;
	min += arr[4];
	min += arr[3];
	min += arr[2];
	min += arr[1];
	// And the max is the sum of the four first array elements
	unsigned long int max = 0;
	max += arr[3];
	max += arr[2];
	max += arr[1];
	max += arr[0];
	cout << min << " " << max << endl;
}

int main() {
	vector<int> arr(5);
	for (int arr_i = 0; arr_i < 5; arr_i++) {
		cin >> arr[arr_i];
	}
	miniMaxSum(arr);
	return 0;
}