#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int arr[9];
int n, m;
int ans[9];

void func(int idx, int num) {
	if (num == m) {
		for (int i = 0; i < m - 1; i++)
			cout << ans[i] << ' ';
		cout << ans[m - 1] << '\n';
		return;
	}

	for (int i = idx + 1; i <= n; i++) {
		ans[num] = arr[i];
		func(i - 1, num + 1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	sort(arr + 1, arr + n + 1);

	func(0, 0);

	return 0;
}