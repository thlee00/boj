#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[1000001];

int solution(vector<int> money) {
    int answer = 0;
    int cnt = 2;
    
    while(cnt--) {
        dp[0] = money[cnt];
        dp[1] = max(dp[0], money[cnt + 1]);

        for (int i = 2; i < money.size() - 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + money[i + cnt]);
        }

        answer = max(answer, dp[money.size() - 2]);

        fill(dp, dp + 1000001, 0);
    }
    
    return answer;
}