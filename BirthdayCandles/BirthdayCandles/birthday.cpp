#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmpFunction(int i, int j) {
	return i > j;
}

int birthdayCakeCandles(int n, vector <int> ar) {
	// Complete this function
	sort(ar.begin(), ar.end(), cmpFunction);
	int count = 1;
	int cmp = ar[0];
	for (int i = 1; i < n; i++) {
		if (ar[i] == cmp) {
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (int ar_i = 0; ar_i < n; ar_i++) {
		cin >> ar[ar_i];
	}
	int result = birthdayCakeCandles(n, ar);
	cout << result << endl;
	return 0;
}