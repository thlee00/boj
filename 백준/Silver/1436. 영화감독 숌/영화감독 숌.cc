#include <iostream>
#include <limits.h>

using namespace std;

long long arr[10001];

int func(long long n) {
	int cnt = 0;
	while (n) {
		if (n % 10 == 6) {
			cnt++;
			if (cnt >= 3)
				return 1;
		}
		else
			cnt = 0;
		n /= 10;
	}
	return 0;
}

int main() {
	int n, cnt = 1;
	cin >> n;

	for (int i = 0; i < LLONG_MAX; i++) {
		if (cnt > n)
			break;
		if (func(i))
			arr[cnt++] = i;
	}

	cout << arr[n];
	return 0;
}