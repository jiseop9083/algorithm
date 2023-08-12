#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#define INF 987654321
using namespace std;

int n;
int num[105];
int dp[105][10][10][10];  // pos번째까지 마지막 3개가 a,b,c일때 최소값

int move(int x, int y) { return (((10 + y) - x) % 10); }

int getNum(int pos, int a, int b, int c) {
  if (pos <= 0) return 0;
  int& ret = dp[pos][a][b][c];
  if (ret != -1) return ret;
  ret = INF;
  if (a == 0) return ret = getNum(pos - 1, b, c, (pos >= 4 ? num[pos - 3] : 0));
  ret = min(ret, getNum(pos - 1, b, c, (pos >= 4 ? num[pos - 3] : 0)) +
                     ((a <= 3 || a >= 7) ? 1 : 2));
  for (int j = -3; j <= 3; j++) {
    if (pos >= 2) {
      ret = min(ret, getNum(pos, move(j, a), move(j, b), c) + 1);
    }
    if (pos >= 3) {
      ret = min(ret, getNum(pos, move(j, a), move(j, b), move(j, c)) + 1);
    }
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(dp, -1, sizeof(dp));
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    int t = (int)(b[i] - a[i]);
    num[i + 1] = t < 0 ? 10 + t : t;
    // cout << num[i + 1] << "\n";
  }
  int answer = getNum(n, num[n], num[n - 1], num[n - 2]);
  cout << min(answer, getNum(n, num[n], num[n - 1], num[n - 2]));
  // int k = 2;
  // cout << "\n" << dp[k][num[k]][num[k - 1]][num[k - 2]];
  return 0;
}