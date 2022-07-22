#include <iostream>
#include <algorithm>
#include<vector>;
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> dp(n + 1);

	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		int min = dp[i - 1] + 1;
		if (i % 3 == 0)
			min = min < dp[i / 3] + 1 ? min : dp[i / 3] + 1;
		if (i % 2 == 0)
			min = min < dp[i / 2] + 1 ? min : dp[i / 2] + 1;
		dp[i] = min;
	}
	cout << dp[n];

	return 0;
}