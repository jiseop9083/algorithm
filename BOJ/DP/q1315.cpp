#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int STR[1005];
int INT[1005];
int PNT[1005];
int dp[1005][1005];
int n;
int answer = 0;

void cnt(int str, int intell) {
  int& ret = dp[str][intell];
  if (ret != -1) return;
  ret = 0;
  int point = 0;
  for (int i = 0; i < n; i++) {
    if (STR[i] <= str || INT[i] <= intell) {
      point += PNT[i];
      ret++;
    }
  }
  answer = max(answer, ret);
  for (int i = str; i < point + 2; i++) {
    int a, b;
    a = i;
    if (intell > point + 2 - a || point + 2 - a <= 0) continue;
    b = point + 2 - i;
    if (a > 1000) a = 1000;
    if (b > 1000) b = 1000;
    cnt(a, b);
  }
}

main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    cin >> STR[i] >> INT[i] >> PNT[i];
  }
  cnt(1, 1);
  cout << answer;
  return 0;
}