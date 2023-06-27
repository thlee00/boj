#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    multiset<string> ms;
    
    for (int i = 0; i < completion.size(); i++)
        ms.insert(completion[i]);
    
    for (int i = 0; i < participant.size(); i++) {
        if (ms.find(participant[i]) == ms.end()) {
            answer = participant[i];
            break;
        }
        ms.erase(ms.find(participant[i]));
    }
    
    return answer;
}