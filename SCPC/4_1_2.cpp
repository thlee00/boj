// 회문인 수의 합

/*
You should use the standard input/output
in order to receive a score properly.
Do not use file input and output
Please be very careful.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

string Answer;

int func(int n) {
	string temp = to_string(n);
	string String = temp;
	int len = temp.length();
	int ret, str;

	for (int i = 0; i < (len + 1) / 2; i++) {
		String[i] = temp[i] <= temp[len - i - 1] ? temp[i] : temp[len - i - 1];
		String[len - i - 1] = String[i];
	}


    stringstream ssInt(String);
	ssInt >> str;

	if (temp[0] == '1')
		ret = (int)pow(10, len - 1) - 1;
	else {
		int first = temp[0] - '0' - 1;
		ret = first;
		for (int i = 0; i < len  - 1; i++) {
			ret *= 10;
			ret += first;
		}
	}

	ret = str > ret ? str : ret;

	return ret;
}

bool compare(int a, int b) {
	return a > b;
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = "";
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		int n, K = 0, remain, temp;
		int arr[10001];

		cin >> n;
		remain = n;

		do {
			temp = func(remain);
			arr[K++] = temp;
			remain -= temp;
		} while (remain);

		sort(arr, arr + K, compare);

		if (K > 3)
			Answer = '0';
		else {
			Answer += to_string(K);
			for (int i = 0; i < K; i++)
				Answer += ' ' + to_string(arr[i]);
		}

		
		/////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
