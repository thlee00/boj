#include <string>
#include <vector>

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    fill(&dp[0][0], &dp[100][100], -1);
    
    for (int i = 0; i < puddles.size(); i++)
        dp[puddles[i][1] - 1][puddles[i][0] - 1] = 0;
    
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
        if (dp[i][0] == -1)
            dp[i][0] = dp[i-1][0];
    for (int j = 1; j < m; j++)
        if (dp[0][j] == -1)
            dp[0][j] = dp[0][j-1];
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i][j] == -1) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
            }
        }
    }
    
    answer = dp[n-1][m-1];
    
    return answer;
}