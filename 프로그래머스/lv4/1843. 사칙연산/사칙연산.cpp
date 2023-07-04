#include <vector>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

int dp[101][101][2];

int solution(vector<string> arr)
{
    int answer = -1;
    int cnt_num = arr.size() / 2 + 1;
    
    for (int i = 0; i < cnt_num; i++) {
        int cur_num = stoi(arr[2 * i]);
        dp[i][i][0] = cur_num;
        dp[i][i][1] = cur_num;
    }
    
    for (int i = 1; i < cnt_num; i++) {
        for (int j = 0; j < cnt_num - i; j++) {
            int cur_max = INT_MIN;
            int cur_min = INT_MAX;
            for (int k = 0; k < i; k++) {
                int temp_max, temp_min;
                if (arr[2 * (j + k) + 1][0] == '-') {
                    temp_max = dp[j][j + k][0] - dp[j + k + 1][j + i][1];
                    temp_min = dp[j][j + k][1] - dp[j + k + 1][j + i][0];
                }
                else {
                    temp_max = dp[j][j + k][0] + dp[j + k + 1][j + i][0];
                    temp_min = dp[j][j + k][1] + dp[j + k + 1][j + i][1];
                }
                
                cur_max = max(cur_max, temp_max);
                cur_min = min(cur_min, temp_min);
            }
            dp[j][j + i][0] = cur_max;
            dp[j][j + i][1] = cur_min;
        }
    }
    
    answer = dp[0][cnt_num - 1][0];
    
    return answer;
}