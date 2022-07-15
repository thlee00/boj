#include <iostream>
#include <queue>

using namespace std;
int tot[1001][1001];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

queue<pair<int, int>> q;
int m, n, ans = -1, chk = 1;

bool valid(int y, int x) {
	if (y >= 0 && y < n) {
		if (x >= 0 && x < m)
			return true;
	}
	return false;
}

int main() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tot[i][j];
			if (tot[i][j] == 0)
				chk = 0;
			else if (tot[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}

	if (chk) {
		cout << 0;
		return 0;
	}

	while (!q.empty()) {
		int Y = q.front().first;
		int X = q.front().second;
		q.pop();

		int a = 4;
		while (a--) {
			int y = Y + dy[a];
			int x = X + dx[a];

			if (valid(y, x) && tot[y][x] == 0) {
				tot[y][x] = tot[Y][X] + 1;
				q.push(make_pair(y, x));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tot[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (ans == -1 || (ans != -1 && tot[i][j] > ans)) {
				ans = tot[i][j];
			}
		}
	}

	cout << ans - 1;
	return 0;
}