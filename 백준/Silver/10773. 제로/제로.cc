#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int arr[100001];

int main() {
	int k, idx = 0, ans = 0;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		if (a == 0)
			idx--;
		else
			arr[idx++] = a;
	}

	for (int i = 0; i < idx; i++)
		ans += arr[i];

	cout << ans;

	return 0;
}