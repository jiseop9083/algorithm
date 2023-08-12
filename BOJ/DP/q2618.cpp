#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int n, w;
pair<int, int> pos[1005];
int dp[1005][1005];
vector<int> answer;

int getDistance(int a, int b) {
  if (a == w || b == w) return 0;
  int& ret = dp[a][b];
  if (ret != -1) return ret;
  int next = max(a, b) + 1;

  int disa = abs(pos[next].first - pos[a].first) +
             abs(pos[next].second - pos[a].second);
  int disb;
  if (b == 0) {
    disb = abs(pos[next].first - n) + abs(pos[next].second - n);
  } else
    disb = abs(pos[next].first - pos[b].first) +
           abs(pos[next].second - pos[b].second);

  return ret = min(getDistance(next, b) + disa, getDistance(a, next) + disb);
}

void getPath(int a, int b) {
  if (a == w || b == w) return;
  int next = max(a, b) + 1;
  int disa = abs(pos[next].first - pos[a].first) +
             abs(pos[next].second - pos[a].second);
  int disb;
  if (b == 0) {
    disb = abs(pos[next].first - n) + abs(pos[next].second - n);
  } else
    disb = abs(pos[next].first - pos[b].first) +
           abs(pos[next].second - pos[b].second);

  int goa = getDistance(next, b) + disa;
  int gob = getDistance(a, next) + disb;
  if (goa > gob) {
    answer.push_back(2);
    getPath(a, next);
  } else {
    answer.push_back(1);
    getPath(next, b);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(dp, -1, sizeof(dp));
  cin >> n >> w;
  for (int i = 1; i <= w; i++) {
    int a, b;
    cin >> a >> b;
    pos[i] = {a, b};
  }
  pos[0] = {1, 1};
  cout << getDistance(0, 0) << "\n";
  getPath(0, 0);
  for (int i : answer) {
    cout << i << "\n";
  }
  return 0;
}