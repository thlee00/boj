#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int arr[1002][1002] = { 0 };

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = arr[i - 1][j] > arr[i][j - 1] ? arr[i - 1][j] : arr[i][j - 1];
		}
	}

	cout << arr[str1.length()][str2.length()];

	return 0;
}