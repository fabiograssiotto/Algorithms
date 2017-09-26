#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const long MAX_N = 300005;
char str[MAX_N];

int main() {
	long long count = 0;
	scanf("%s", str);
	long n = strlen(str);

	for (long i = 0; i < n; i++) {
		// count ocurrences of single-digit
		if (str[i] == '0' || str[i] == '4' || str[i] == '8') {
			count++;
		}
	}

	for (long i = 0; i < n - 1; ++i) {
		int h = (str[i] - '0') * 10 + (str[i + 1] - '0');
		if (h % 4 == 0)
			count = count + i + 1;
	}
	printf("%I64d\n", count);
}