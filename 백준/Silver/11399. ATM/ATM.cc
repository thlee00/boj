#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, ans = 0;
	int time[1001];
	int sum[1001];
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> time[i];

	sort(time, time + n);

	sum[0] = time[0];
	ans = time[0];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + time[i];
		ans += sum[i];
	}

	cout << ans;

	return 0;
}