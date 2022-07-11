#include <iostream>
#include <string>
using namespace std;

int func(int input) {
	string temp;
	temp = to_string(input);

	for (int i = 0; i < temp.length() / 2 + 1; i++) {
		if (temp[i] != temp[temp.length() - i - 1])
			return 0;
	}
	return 1;
}

int main() {
	while (1) {
		int input;
		cin >> input;

		if (!input)
			break;
		else {
			if (func(input))
				cout << "yes\n";
			else
				cout << "no\n";
		}
	}

	return 0;
}