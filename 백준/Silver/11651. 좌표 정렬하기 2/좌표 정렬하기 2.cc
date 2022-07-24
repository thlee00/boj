#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<pair<int, int>> arr;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (b.second == a.second)
		return b.first > a.first;
	else
		return b.second > a.second;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr.push_back(make_pair(x, y));
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n - 1; i++)
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	cout << arr[n - 1].first << ' ' << arr[n - 1].second;

	return 0;
}