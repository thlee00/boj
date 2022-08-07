#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int str[1001];
int rht[1001];
int lft[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (str[j] < str[i])
				max = max > rht[j] ? max : rht[j];
		}
		rht[i] = max + 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		int max = 0;
		for (int j = n - 1; j > i; j--) {
			if (str[j] < str[i])
				max = max > lft[j] ? max : lft[j];
		}
		lft[i] = max + 1;
	}

	for (int i = 0; i < n; i++) {
		int cur = rht[i] + lft[i];
		ans = cur > ans ? cur : ans;
	}

	cout << ans - 1;

	return 0;
}