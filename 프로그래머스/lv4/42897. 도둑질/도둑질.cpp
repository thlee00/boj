#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[1000001];

int solution(vector<int> money) {
    int answer = 0;
    
    dp[0] = money[0];
    dp[1] = max(dp[0], money[1]);
    
    for (int i = 2; i < money.size() - 1; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    }
    
    answer = dp[money.size() - 2];
    
    fill(dp, dp + 1000001, 0);
    
    dp[0] = money[1];
    dp[1] = max(dp[0], money[2]);
    
    for (int i = 2; i < money.size() - 1; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i + 1]);
    }
    
    answer = max(answer, dp[money.size() - 2]);
    
    return answer;
}