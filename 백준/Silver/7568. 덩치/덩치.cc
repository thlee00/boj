#include <iostream>

using namespace std;

pair<int,int> arr[51];
int ans[51];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	for (int i = 0; i < n; i++) {
		int temp = 1;
		int x = arr[i].first;
		int y = arr[i].second;
		for (int j = 0; j < n; j++) {
			if (j != i) {
				if (arr[j].first > x && arr[j].second > y) {
					temp++;
				}
			}
		}
		ans[i] = temp;
	}

	for (int i = 0; i < n - 1; i++) {
		cout << ans[i] << " ";
	}
	cout << ans[n - 1];
	return 0;
}