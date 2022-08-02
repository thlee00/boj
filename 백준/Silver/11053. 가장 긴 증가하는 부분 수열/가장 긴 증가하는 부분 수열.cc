#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
int n;
int arr[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				max = max > dp[j] ? max : dp[j];
			}
		}
		dp[i] = max + 1;
		ans = ans > dp[i] ? ans : dp[i];
	}

	cout << ans;

	return 0;

}