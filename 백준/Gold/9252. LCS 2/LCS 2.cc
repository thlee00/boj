#include <iostream>
#include <vector>
#include <string>

using namespace std;

int arr[1001][1001];
string a, b;

void print_res(int i, int j) {
	if (i == 0 || j == 0)
		return;
	if (b[i - 1] == a[j - 1]) {
		print_res(i - 1, j - 1);
		cout << b[i-1];
	}
	else
		arr[i][j - 1] > arr[i - 1][j] ? print_res(i, j - 1) : print_res(i - 1, j);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < a.length(); j++) {
			if (b[i] == a[j])
				arr[i + 1][j + 1] = arr[i][j] + 1;
			else
				arr[i + 1][j + 1] = arr[i][j + 1] > arr[i + 1][j] ? arr[i][j + 1] : arr[i + 1][j];
		}
	}

	int i = b.length();
	int j = a.length();

	int res = arr[i][j];
	cout << res;

	if (res) {
		cout << '\n';
		print_res(i, j);
	}

	return 0;
}