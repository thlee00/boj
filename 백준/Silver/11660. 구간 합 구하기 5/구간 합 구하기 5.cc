#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
int arr[1025][1025];
int dp[1025][1025];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			/* simple version
			dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + arr[i][j];
			*/
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = arr[i][j];
			if (i != 0)
				dp[i][j] += dp[i - 1][j];
			if (j != 0)
				dp[i][j] += dp[i][j - 1];
			if (i != 0 && j != 0)
				dp[i][j] -= dp[i - 1][j - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		int ans = dp[x2][y2];
		if (y1 != 0)
			ans -= dp[x2][y1 - 1];
		if (x1 != 0)
			ans -= dp[x1 - 1][y2];
		if (x1 != 0 && y1 != 0)
			ans += dp[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}

	return 0;

}