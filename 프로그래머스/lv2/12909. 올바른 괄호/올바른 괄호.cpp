#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> parentheses;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            parentheses.push(s[i]);
        }
        else if (s[i] == ')') {
            if (parentheses.empty())
                return false;
            else
                parentheses.pop();
        }
    }
    if(!parentheses.empty())
        answer = false;
    
    return answer;
}