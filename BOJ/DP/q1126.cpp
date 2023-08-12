#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int dp[55][500005];  // i번째까지 차이가 j일때 작은블럭의 최대 높이(0 base)
int n;
int num[500005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  sort(num, num + n);
  int sum = num[0];
  memset(dp, -1, sizeof(dp));
  dp[0][num[0]] = 0;
  for (int i = 1; i < n; i++) {
    sum += num[i];
    dp[i][num[i]] = 0;
    for (int j = sum; j >= 0; j--) {
      if (dp[i - 1][j] == -1) continue;
      dp[i][j] = max(dp[i - 1][j], dp[i][j]);

      int b = dp[i - 1][j];
      int a = b + j;
      //  cout << a << " " << b << "\n";
      dp[i][abs(b + num[i] - a)] =
          max(dp[i][abs(b + num[i] - a)], min(b + num[i], a));
      dp[i][abs(a + num[i] - b)] =
          max(dp[i][abs(a + num[i] - b)], min(a + num[i], b));
    }
  }
  /* for (int i = 0; i < n; i++) {
     for (int j = 0; j <= 64; j++) {
       cout << dp[i][j] << " ";
     }
     cout << "\n";
   }*/
  cout << dp[n - 1][0];
  return 0;
}