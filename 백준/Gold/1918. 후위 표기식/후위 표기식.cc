#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string input;
	cin >> input;

	stack<char> oper;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(')
			oper.push(input[i]); // 여는 괄호 나오면 push
		else if (input[i] == '*' || input[i] == '/') { // *, / 일 때는
			while (!oper.empty() && (oper.top() == '*' || oper.top() == '/')) { // 여기를 || 할 걸 &&로 해서 틀렸었음
				// 연산자 우선순위가 낮은 +, - 인 경우 나중에 출력되어야 함 (나중에 계산된다는 뜻)
				// 연산자 우선순위가 낮지 않은 *, /의 경우 출력되게끔
				cout << oper.top();
				oper.pop();
			}
			oper.push(input[i]);
		}
		else if (input[i] == '+' || input[i] == '-') { // +, - 일 때는
			while (!oper.empty() && oper.top() != '(') {
				// 연산자 우선순위가 전부 낮지 않음 (+, -, *, /)
				// 우선순위가 높은, 순서가 먼저 나온 애들이 먼저 출력 되어야 함
				// (의 경우 출력되면 안됨 (닫는 괄호가 있을 때 pop만 해주면 됨)
				// )의 경우 고려할 필요 없음 (push 자체를 안해주기 때문에)
				cout << oper.top();
				oper.pop();
			}
			oper.push(input[i]);
		}
		else if (input[i] == ')') { // 닫는 괄호 나오면
			while (!oper.empty() && oper.top() != '(') {
				cout << oper.top();
				oper.pop();
			}
			oper.pop(); // 여는 괄호 나올 때까지 pop 해줌
		}
		else
			cout << input[i]; // 알파벳은 그냥 일단 출력
	}

	while (!oper.empty()) {
		cout << oper.top();
		oper.pop();
	}
	// 만약 stack에 원소가 남아있는 경우 비워 줌
	// A+(B*C)-(D/E) 같은 경우 마지막 )에서 ( 나올 때까지 pop한 이후에도 -가 남아있음

	return 0;
}

//A+(C-N*(U-O)+Q)
//ACNUO-*-Q++

//A*B-C*D/E
//AB*CD*E/-