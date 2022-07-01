#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	long long ans = 0;
	cin >> n >> m;

	vector<long long> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	while(m--) {
		sort(arr.begin(), arr.end());

		long long temp = arr[0] + arr[1];
		arr[0] = temp;
		arr[1] = temp;
	}

	for (int i = 0; i < n; i++)
		ans += arr[i];
	
	cout << ans;
	return 0;
}