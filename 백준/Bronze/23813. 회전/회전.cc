#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	long long N;
	long long temp = 0;
	long long res = 0;
	int cnt = 0;

	cin >> N;

	while (N) {
		temp += (N % 10) * pow(10, cnt++);
		N /= 10;
		string str = to_string(temp);
		if (N)
			str += to_string(N);
		res += stoi(str) % 987654322;
	}

	cout << res;

	return 0;
}