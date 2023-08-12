#include <algorithm>
#include <iostream>
using namespace std;

int dp[105];
pair<int, int> num[105];
int n;

bool com(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}

int upper(int start, int end, int x) {
  int mid;
  while (start < end) {
    mid = (start + end) / 2;
    if (dp[mid] <= x)
      start = mid + 1;
    else
      end = mid;
  }
  return end;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    num[i] = {a, b};
  }
  sort(num, num + n, com);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int pos = upper(0, cnt, num[i].second);
    if (pos < cnt) {
      dp[pos] = num[i].second;
    } else {
      dp[cnt] = num[i].second;
      cnt++;
    }
  }
  cout << n - cnt << "\n";
  return 0;
}