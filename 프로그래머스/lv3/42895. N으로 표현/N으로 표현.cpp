#include <string>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    
    unordered_set<int> number_set[8];

    int temp = 0;
    for (int i = 0; i < 8; i++) {
        temp *= 10;
        temp += N;
        number_set[i].insert(temp);
    }
    
    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            for (auto x : number_set[j]) {
                for (auto y : number_set[i - j - 1]) {
                    number_set[i].insert(x + y);
                    number_set[i].insert(x - y);
                    number_set[i].insert(x * y);
                    if (y != 0)
                        number_set[i].insert(x / y);
                }
            }
        }
    }
    
    for (int i = 0; i < 8; i++) {
        if (number_set[i].find(number) != number_set[i].end()) {
            answer = i + 1;
            break;
        }
    }

    return answer;
}