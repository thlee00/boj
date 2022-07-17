#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int arr[21][21];
int check[21][21];
int X, Y;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
int min_dist, minx, miny;
int n, ans = 0, eat = 0, baby = 2;

void init() {
	min_dist = 401;
	miny = 21;
	minx = 21;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			check[i][j] = -1;
	}
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	check[y][x] = 0;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		int y = cur.first;
		int x = cur.second;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (check[ny][nx] != -1 || arr[ny][nx] > baby)
				continue;

			check[ny][nx] = check[y][x] + 1;
			if (arr[ny][nx] != 0 && arr[ny][nx] < baby) {
				if (min_dist > check[ny][nx]) {
					minx = nx;
					miny = ny;
					min_dist = check[ny][nx];
				}
				else if (min_dist == check[ny][nx]) {
					if (miny == ny) {
						if (minx > nx) {
							minx = nx;
							miny = ny;
						}
					}
					else if (miny > ny) {
						minx = nx;
						miny = ny;
					}
				}
			}
			q.push(make_pair(ny, nx));
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				Y = i;
				X = j;
				arr[i][j] = 0;
			}
		}
	}

	while (1) {
		init();
		bfs(Y, X);

		if (minx != 21 && miny != 21) {
			ans += check[miny][minx];
			eat++;
			if (eat == baby) {
				baby++;
				eat = 0;
			}
			arr[miny][minx] = 0;
			X = minx;
			Y = miny;
		}
		else
			break;
	}

	cout << ans;
	return 0;
}