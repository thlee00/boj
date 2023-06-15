#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    answer.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        int temp = arr[i];
        if (answer[answer.size() - 1] != temp) {
            answer.push_back(temp);
        }
    }

    return answer;
}