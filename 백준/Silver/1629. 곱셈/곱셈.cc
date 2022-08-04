#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long a, b, c;
	cin >> a >> b >> c;

	long long ans = 1;
	while (b) {
		if (b % 2)
			ans = (ans * a) % c;
		a = (a * a) % c;
		b /= 2;
	}

	cout << ans;

	return 0;
}

