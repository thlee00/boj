#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	int ans[12];
	cin >> t;

	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;
	for (int i = 4; i < 12; i++) {
		ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
	}

	while (t--) {
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0;
}