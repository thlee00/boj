#include <iostream>
#include <string>

using namespace std;

bool checkU(string str, int* idx) {
	if (*idx > str.size())
		return false;
	str = str.substr(*idx);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'U') {
			*idx += i + 1;
			return true;
		}
	}
	return false;
}

bool checkC(string str, int* idx) {
	if (*idx > str.size())
		return false;
	str = str.substr(*idx);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'C') {
			*idx += i + 1;
			return true;
		}
	}
	return false;
}

bool checkP(string str, int* idx) {
	if (*idx > str.size())
		return false;
	str = str.substr(*idx);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'P') {
			*idx += i + 1;
			return true;
		}
	}
	return false;
}

int main() {
	string str;
	int i = 0;
	getline(cin, str);

	if (!checkU(str, &i))
		cout << "I hate UCPC";
	else {
		if (!checkC(str, &i))
			cout << "I hate UCPC";
		else {
			if (!checkP(str, &i))
				cout << "I hate UCPC";
			else {
				if (!checkC(str, &i))
					cout << "I hate UCPC";
				else {
					cout << "I love UCPC";
				}
			}
		}
	}
	
	return 0;
}