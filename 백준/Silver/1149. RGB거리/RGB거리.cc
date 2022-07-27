#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	int dp[1001][3];
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
	for (int i = 1; i < n; i++) {
		int r, g, b;
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
		dp[i][0] += dp[i - 1][1] < dp[i - 1][2] ? dp[i - 1][1] : dp[i - 1][2];
		dp[i][1] += dp[i - 1][0] < dp[i - 1][2] ? dp[i - 1][0] : dp[i - 1][2];
		dp[i][2] += dp[i - 1][0] < dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1];
	}

	int min = dp[n - 1][0] < dp[n - 1][1] ? dp[n - 1][0] : dp[n - 1][1];
	min = min < dp[n - 1][2] ? min : dp[n - 1][2];
	cout << min;

	return 0;

}