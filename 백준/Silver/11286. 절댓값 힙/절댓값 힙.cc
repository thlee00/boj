#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct cmp{
	bool operator()(long long &a, long long &b) {
		int abs_a = a > 0 ? a : -a;
		int abs_b = b > 0 ? b : -b;

		if (abs_a == abs_b)
			return a > b;
		else
			return abs_a > abs_b;
	}
};

int main() {
	int n;
	priority_queue<long long, vector<long long>, cmp> pq;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (!x) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
	return 0;
}