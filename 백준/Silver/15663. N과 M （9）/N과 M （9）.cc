#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int arr[9];
int n, m;
int visited[9] = {0};
int ans[9];

void func(int num) {
	if (num == m) {
		for (int i = 0; i < m - 1; i++)
			cout << ans[i] << ' ';
		cout << ans[m - 1] << '\n';
		return;
	}

	int pre = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i] || pre == arr[i])
			continue;
			// 직전에 방문한 거랑 똑같으면 함수 호출할 필요가 없음

		ans[num] = arr[i];
		pre = ans[num];

		visited[i] = true;
		func(num + 1);
		visited[i] = false;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	func(0);

	return 0;
}