#include <iostream>
#include <algorithm>
#include<vector>;
using namespace std;

int main() {
	int n, k, ans = 0;
	cin >> n >> k;
	vector<int> coin;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp <= k)
			coin.push_back(temp);
	}

	for (int i = coin.size() - 1; i >= 0; i--) {
		int num = k / coin[i];
		ans += num;
		k -= coin[i] * num;
	}

	cout << ans;

	return 0;
}