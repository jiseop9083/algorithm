// sorting auffix array(Manber-Myers Algorithm)
// LCP Array(Kasai’s algorithm)

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t;
vector<int> group;

bool com(int x, int y) {
  // same group number
  if (group[x] == group[y]) return group[x + t] < group[y + t];
  // different group number
  return group[x] < group[y];
}

vector<int> getSuffixArray(const string& s) {
  int n = s.size();
  t = 1;
  // prevent overflow: a + t <= n
  group.resize(n + 1);
  for (int i = 0; i < n; i++) group[i] = s[i] - 'a';
  group[n] = -1;
  vector<int> sa(n);
  for (int i = 0; i < n; i++) sa[i] = i;
  while (t < n) {
    sort(sa.begin(), sa.end(), com);
    if (2 * t >= n) break;
    vector<int> newGroup(n + 1);
    newGroup[n] = -1;
    newGroup[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (com(sa[i - 1], sa[i]))
        // Case: different group to t'th char
        newGroup[sa[i]] = newGroup[sa[i - 1]] + 1;
      else  // Case: same from first char to t'th char
        newGroup[sa[i]] = newGroup[sa[i - 1]];
    }
    group = newGroup;
    t *= 2;
  }
  return sa;
}

vector<int> getLCP(const string& s) {
  int n = s.size();
  vector<int> sa = getSuffixArray(s);

  vector<int> ranking(n);  // longger string first
  vector<int> lcp(n);
  for (int i = 0; i < n; i++) ranking[sa[i]] = i;
  int len = 0;
  for (int i = 0; i < n; i++) {
    int k = ranking[i];
    if (k) {
      int j = sa[k - 1];
      while (s[j + len] == s[i + len]) len++;
      lcp[k] = len;
      if (len) len--;
    }
  }
  return lcp;
}
