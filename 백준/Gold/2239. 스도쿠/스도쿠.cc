#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
int delta_y[] = { -1, 0, 1 };

vector<pair<int, int>> nullpts;
bool complete = false;

int check(int i, int j, int num) {
	for (int x = 0; x < 9; x++) {
		if (i == x);
		else if (board[x][j] == num)
			return false;
	}
	for (int y = 0; y < 9; y++) {
		if (y == j);
		else if (board[i][y] == num)
			return false;
	}
	for (int x = 3 * (i / 3); x < 3 * (i / 3) + 3; x++)
		for (int y = 3 * (j / 3); y < 3 * (j / 3) + 3; y++)
		{
			if (board[x][y] == num)
			{
				if (x != i && y != j)
					return false;
			}
		}
	return true;
}

void sudoku(int N) {
	if (N == nullpts.size()) {
		complete = true;
		return;
	}

	int i = nullpts[N].first;
	int j = nullpts[N].second;

	for (int k = 1; k <= 9; k++) {
		board[i][j] = k;
		if (check(i, j, k))
			sudoku(N + 1);
		if (complete)
			return;
	}
	board[i][j] = 0;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char a;
			cin >> a;
			board[i][j] = a - '0';
			if (board[i][j] == 0) {
				nullpts.push_back(make_pair(i, j));
			}
		}
	}

	sudoku(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j];
		cout << '\n';
	}

	return 0;
}