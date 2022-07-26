#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> tri(n+1);
	for (int i = 1; i <= n; i++) {
		vector<int> temp(i+1);
		for (int j = 1; j <= i; j++)
			cin >> temp[j];
		tri[i] = temp;
	}

	for (int i = n - 1; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			tri[i][j] += tri[i + 1][j] > tri[i + 1][j + 1] ? tri[i + 1][j] : tri[i + 1][j + 1];
		}
	}

	cout << tri[1][1];

	return 0;

}