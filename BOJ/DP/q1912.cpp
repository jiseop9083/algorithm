#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> dp[100005];  // 전체, 부분

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int b;
  cin >> b;
  dp[0] = {b, b};
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    dp[i].first = max(dp[i - 1].first + a, a);
    dp[i].second = max(dp[i].first, dp[i - 1].second);
  }

  cout << dp[n - 1].second;
  return 0;
}