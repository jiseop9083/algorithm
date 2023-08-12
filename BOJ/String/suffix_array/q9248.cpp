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

vector<int> getSuffixArray(string& s) {
  int n = s.size();
  t = 1;
  group.resize(n + 1);
  for (int i = 0; i < n; i++) group[i] = s[i];
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
        newGroup[sa[i]] = newGroup[sa[i - 1]] + 1;
      else
        newGroup[sa[i]] = newGroup[sa[i - 1]];
    }
    group = newGroup;
    t *= 2;
  }
  return sa;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string arr;
  cin >> arr;
  int n = arr.size();
  vector<int> sa = getSuffixArray(arr);
  vector<int> ranking(n + 1);
  vector<int> lcp(n);
  for (int i = 0; i < n; i++) ranking[sa[i]] = i;
  int len = 0;
  for (int i = 0; i < n; i++) {
    int k = ranking[i];
    if (k) {
      int j = sa[k - 1];
      while (arr[j + len] == arr[i + len]) len++;
      lcp[k] = len;
      if (len) len--;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << sa[i] + 1 << " ";
  }
  cout << "\nx ";
  for (int i = 1; i < n; i++) {
    cout << lcp[i] << " ";
  }
  return 0;
}