#include <iostream>
#include <string>
#include <cmath>

long long maximum = 1000000000000000001;

using namespace std;

long long max(long long a, long long b) {
	return a > b ? a : b;
}

int main() {
	long long d, n, m, k, res;

	cin >> d >> n >> m >> k;

	long long N = n / d;
	long long M = m / d;

	long long n_need = d - n % d;
	long long m_need = d - m % d;

	long long res1 = (k - n_need - m_need) / d + 2;
	long long res2 = (k - n_need) / d + 1;
	res = res1 > res2 ? k - n_need - m_need : k - n_need;

	long long res3 = (k - m_need) / d + 1;
	if (res3 > max(res1, res2))
		res = k - m_need;
	else if (res3 == max(res1, res2))
		res = max(k - m_need, res);

	long long res4 = k / d;
	if (res4 > max(res3, max(res1, res2)))
		res = k;
	else if (res4 == max(res3, max(res1, res2)))
		res = max(k, res);

	cout << res;

	return 0;
}