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
	vector<int> arr;
	vector<int> L;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		auto idx = lower_bound(L.begin(), L.end(), input);
		if (idx == L.end())
			L.push_back(input);
		else
			*idx = input;
	}

	cout << L.size();

	return 0;
}