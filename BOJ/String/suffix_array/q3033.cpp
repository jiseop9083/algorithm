#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t;
vector<int> group;

bool com(int a, int b) {
  if (group[a] != group[b]) return group[a] < group[b];
  return group[a + t] < group[b + t];
}

vector<int> getSuffixArray(const string& s) {
  int n = s.size();
  t = 1;
  group.resize(n + 1);
  for (int i = 0; i < n; i++) group[i] = s[i];
  group[n] = -1;
  vector<int> perm(n);
  for (int i = 0; i < n; i++) perm[i] = i;
  while (t < n) {
    sort(perm.begin(), perm.end(), com);

    if (2 * t >= n) break;
    vector<int> newGroup(n + 1);
    newGroup[n] = -1;
    newGroup[perm[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (com(perm[i - 1], perm[i]))
        newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
      else
        newGroup[perm[i]] = newGroup[perm[i - 1]];
    }
    group = newGroup;
    t *= 2;
  }
  return perm;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  string arr;
  cin >> n >> arr;
  vector<int> perm = getSuffixArray(arr);
  vector<int> ra(n + 1);
  vector<int> lcp(n + 1);

  for (int i = 0; i < n; i++) ra[perm[i]] = i;
  int len = 0;
  for (int i = 0; i < n; i++) {
    // 가장 긴 문자열부터
    int k = ra[i];
    if (k) {
      int j = perm[k - 1];
      // 그냥 구하기
      while (arr[j + len] == arr[i + len]) len++;
      lcp[k] = len;
      if (len) len--;
    }
  }
  int answer = 0;
  for (int i : lcp) {
    answer = max(answer, i);
  }
  cout << answer;
  return 0;
}
