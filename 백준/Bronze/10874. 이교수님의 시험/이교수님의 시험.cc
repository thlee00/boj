#include <iostream>

using namespace std;

int main() {
	
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int score = 0;
		for (int j = 1; j <= 10; j++) {
			int num;
			cin >> num;

			int ans = (j - 1) % 5 + 1;
			if (num == ans)
				score++;
		}
		if (score == 10)
			cout << i << endl;
	}

	return 0;
}