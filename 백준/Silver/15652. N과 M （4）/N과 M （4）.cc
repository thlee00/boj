#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
int n, m;
int ans[9] = { 0 };

void func(int idx, int num) {
	if (num == m) {
		for (int i = 0; i < m - 1; i++)
			cout << ans[i] << " ";
		cout << ans[m - 1] << "\n";
		return;
	}

	for (int i = idx + 1; i <= n; i++) {
		ans[num] = i;
		func(i - 1, num + 1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	func(0, 0);

	return 0;

}