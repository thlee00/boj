#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int arr[2001];
int dp[2001][2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (arr[j] == arr[j + i]) {
				if (i == 1 || dp[j + 1][j + i - 1] == 1)
					dp[j][j + i] = 1;
			}
		}
	}

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << dp[a][b] << '\n';
	}

	return 0;
}