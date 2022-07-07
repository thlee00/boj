#include <iostream>

using namespace std;

int arr[101];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int temp = arr[i] + arr[j] + arr[k];
				if (temp <= m)
					if (temp > ans)
						ans = temp;
			}
		}
	}

	cout << ans;
	return 0;
}