#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n;
int dp[105][105];
int line[105][105];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  memset(line, 0, sizeof(line));
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    line[a][b] = 1;
    line[b][a] = 1;
  }
  for (int i = 1; i <= 100; i++) {
    for (int j = i; j >= 1; j--) {
      for (int k = j; k < i; k++) {  // 업데이트 순서 주의
        dp[j][i] = max(dp[j][i], dp[j][k] + dp[k][i] + line[j][i]);
      }
    }
  }
  cout << dp[1][100];
  return 0;
}