#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

string arr[101][101];

string add(string a, string b) {
	string ret = "";
	int sub_sum = 0;
	int size = a.size() > b.size() ? a.size() : b.size();

	for (int i = 0; i < size || sub_sum != 0; i++) {
		if (a.size() > i)
			sub_sum += a[i] - '0';
		if (b.size() > i)
			sub_sum += b[i] - '0'; // a, b 자리 수를 넘지 않는 경우 해당 자리 수 합 구하기

		ret += to_string(sub_sum % 10); // 해당 자리 숫자를 문자열에 더해줌
		sub_sum /= 10;
	}

	return ret;
}

string comb(int n, int m) {
	if (n == m || m == 0)
		return "1";

	if (arr[n][m] != "")
		return arr[n][m];

	arr[n][m] = add(comb(n - 1, m - 1), comb(n - 1, m));

	return arr[n][m];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	comb(n, m);

	for (int i = arr[n][m].length() - 1; i >= 0; i--)
		cout << arr[n][m][i];

	return 0;
}