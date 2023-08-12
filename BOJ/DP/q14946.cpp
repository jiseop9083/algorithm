#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int v, q, k;
vector<int> ve[1005];
int visit[1005];
int rgb[1005][3];
int dp[1005][10][3];
int trans[3] = {3, 5, 2};

int bfs(int x, int cost, int color) {  // node, cost
  int& ret = dp[x][cost][color];
  if (ret != -1) return ret;
  ret = 0;
  bool isEnd = true;
  visit[x] = 1;
  cost = (cost + (k * 10) - rgb[x][color]) % k;
  for (int i : ve[x]) {
    if (visit[i]) continue;
    if (color == 0) {
      ret = (ret + bfs(i, cost, 0)) % q;
      ret = (ret + bfs(i, cost, 1)) % q;
    }
    if (color == 1) {
      ret = (ret + bfs(i, cost, 0)) % q;
      ret = (ret + bfs(i, cost, 2)) % q;
    }
    if (color == 2) {
      ret = (ret + bfs(i, cost, 1)) % q;
    }
    isEnd = false;
  }
  if (isEnd) {
    if (cost == 0) {
      ret = 1;
    } else {
      ret = 0;
    }
  }
  visit[x] = 0;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(visit, 0, sizeof(visit));
  memset(dp, -1, sizeof(dp));
  cin >> v >> q >> k;
  for (int i = 0; i < v - 1; i++) {
    int a, b;
    cin >> a >> b;
    ve[a].push_back(b);
    ve[b].push_back(a);
  }
  for (int i = 1; i <= v; i++) {
    cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
  }
  int answer = 0;
  for (int i = 0; i < 3; i++) {
    answer = (answer + bfs(1, 0, i)) % q;
  }
  cout << answer << "\n";
  /*for (int i = 1; i <= v; i++) {
    for (int j = 0; j < k; j++) {
      for (int l = 0; l < 3; l++) {
        cout << dp[i][j][l] << " ";
      }
      cout << "\n";
    }
    cout << "\n\n";
  }*/
  return 0;
}