#include <iostream>
#include <string>
using namespace std;

int arr0[41];
int arr1[41];

int main() {
	int t;
	cin >> t;

	arr0[0] = 1;
	arr1[0] = 0;

	arr0[1] = 0;
	arr1[1] = 1;

	for (int i = 2; i <= 40; i++) {
		arr0[i] = arr0[i - 1] + arr0[i - 2];
		arr1[i] = arr1[i - 1] + arr1[i - 2];
	}

	while (t--) {
		int n;
		cin >> n;

		cout << arr0[n] << ' ' << arr1[n] << '\n';
	}

	return 0;
}