#include <cstring>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  long long dp[105][10][1 << 11];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      for (int j = 1; j <= 9; j++) {
        dp[i][j][1 << j] = 1;
      }
      dp[1][0][1 << 0] = 0;
      continue;
    }
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k < 1 << n; k++) {
        if (j == 0 && (k & 1 << 0) == 1 << 0) {
          dp[i][j][k] = dp[i - 1][1][k] + dp[i - 1][1][k - (1 << 0)];
        } else if (j == 9 && (k & 1 << 9) == 1 << 9) {
          dp[i][j][k] = dp[i - 1][8][k] + dp[i - 1][8][k - (1 << 9)];
        } else {
          dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
      }
    }
  }
  long long answer = 0;
  for (int i = 0; i <= 9; i++) {
    answer = (answer + dp[n][i]) % 1000000000;
  }
  cout << answer;
  return 0;
}