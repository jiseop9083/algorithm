#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int n;
int dp[105][105];
string pattern;

bool isMatch(int w, int s, string arr) {
  int& ret = dp[w][s];
  if (ret != -1) return ret;
  if (s < arr.size() && w < pattern.size() && pattern[w] == arr[s]) {
    return ret = isMatch(w + 1, s + 1, arr);
  }
  if (w == pattern.size()) return ret = (s == arr.size());

  if (pattern[w] == '*')
    if (isMatch(w + 1, s, arr) || (s < arr.size() && isMatch(w, s + 1, arr))) {
      return ret = 1;
    }
  return ret = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> pattern;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string arr;
    cin >> arr;
    memset(dp, -1, sizeof(dp));
    if (isMatch(0, 0, arr)) {
      cout << arr << "\n";
    }
  }
  return 0;
}