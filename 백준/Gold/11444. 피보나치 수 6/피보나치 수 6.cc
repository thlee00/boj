#include <iostream>
#include <algorithm>
#include <vector>;
#include <string>
#define mod 1000000007
using namespace std;

long long n;
typedef vector<vector<long long>> mat;

mat operator* (mat& a, mat&b) {
	mat c(2, vector<long long>(2));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];
			c[i][j] %= mod;
		}
	}

	return c;
}

int main() {
	cin >> n;
	mat ans = { {1,0},{0,1} };
	mat a = { {1,1},{1,0} };

	while (n) {
		if (n % 2 == 1)
			ans = ans * a;
		a = a * a;
		n /= 2;
	}

	cout << ans[0][1];

	return 0;
}