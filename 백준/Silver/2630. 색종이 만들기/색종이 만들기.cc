#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int n;
int paper[129][129];

typedef pair<pair<int, int>, int> p;

int check(p cur) {
	int size = cur.second;
	int y = cur.first.first;
	int x = cur.first.second;
	int res = 2;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (paper[y + i][x + j] == 1) {
				if (res == 2)
					res = 1;
				else if (res == 0)
					return 2;
			}
			else {
				if (res == 2)
					res = 0;
				else if (res == 1)
					return 2;
			}
		}
	}
	return res;
}

int main() {
	int white = 0, blue = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> paper[i][j];
	}
	queue<p> q;
	q.push(make_pair(make_pair(1, 1), n));

	while (!q.empty()) {
		p cur = q.front();
		q.pop();
		int temp = check(cur);
		if (temp == 2) {
			int y = cur.first.first;
			int x = cur.first.second;
			int nxt_size = cur.second / 2;
			q.push(make_pair(make_pair(y, x), nxt_size));
			q.push(make_pair(make_pair(y, x + nxt_size), nxt_size));
			q.push(make_pair(make_pair(y + nxt_size, x), nxt_size));
			q.push(make_pair(make_pair(y + nxt_size, x + nxt_size), nxt_size));

		}
		else if (temp == 1)
			blue++;
		else if (temp == 0)
			white++;
	}

	cout << white << '\n' << blue;

	return 0;
}