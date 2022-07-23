#include <iostream>
#include <algorithm>
#include <vector>;
#include <string>
using namespace std;

int n, m;

void func(int idx, int num, string ans) {
	if (num < 1) {
		cout << ans << "\n";
		return;
	}
	if (idx > n)
		return;
	
	func(idx + 1, num - 1, ans + " " + to_string(idx));
	func(idx + 1, num, ans);
	return;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n - m + 1; i++)
		func(i + 1, m - 1, to_string(i));

	return 0;
}