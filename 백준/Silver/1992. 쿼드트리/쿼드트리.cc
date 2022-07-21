#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int n;
int video[65][65] = { 0 };

typedef pair<pair<int, int>, int> p;
string ans = "";

void func(p cur) {
	int size = cur.second;
	int y = cur.first.first;
	int x = cur.first.second;
	int res = 2, brk = 0;

	if (size == 0) {

	}
	else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (video[y + i][x + j] == 1) {
					if (res == 2)
						res = 1;
					else if (res == 0) {
						res = 2;
						brk = 1;
						break;
					}
				}
				else {
					if (res == 2)
						res = 0;
					else if (res == 1) {
						res = 2;
						brk = 1;
						break;
					}
				}
			}
			if (brk) {
				brk = 0;
				break;
			}
		}

		if (res == 2) {
			ans += '(';
			func(make_pair(make_pair(y, x), size / 2));
			func(make_pair(make_pair(y, x + size / 2), size / 2));
			func(make_pair(make_pair(y + size / 2, x), size / 2));
			func(make_pair(make_pair(y + size / 2, x + size / 2), size / 2));
			ans += ')';
		}
		else if (res == 1) {
			ans += '1';
		}
		else if (res == 0) {
			ans += '0';
		}
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char a;
			cin >> a;
			if (a == '1')
				video[i][j] = 1;
		}
	}

	func(make_pair(make_pair(1, 1), n));

	cout << ans;

	return 0;
}