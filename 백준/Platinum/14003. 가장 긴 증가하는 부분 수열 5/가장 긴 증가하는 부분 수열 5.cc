#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	vector<long long> arr;
	vector<long long> ans;
	vector<int> L;
	cin >> n;

	vector<int> pos(n);

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		arr.push_back(input);
		auto idx = lower_bound(L.begin(), L.end(), input);
		if (idx == L.end()) {
			L.push_back(input);
			pos[i] = L.size() - 1;
		}
		else {
			*idx = input;
			pos[i] = idx - L.begin();
		}
	}

	int len = L.size();
	cout << len << '\n';

	ans.resize(len--);

	for (int i = n - 1; i >= 0; i--) {
		if (pos[i] == len) {
			ans[len] = arr[i];
			len--;
		}

		if (len < 0)
			break;
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';

	return 0;
}