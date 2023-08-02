#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> get_pi(string pattern) {  // O(n^2)
  int len = pattern.size();
  vector<int> pi(len, 0);
  // exception: pi[0] = 0
  pi[0] = 0;
  for (int start = 1; start < len; start++) {
    for (int i = 0; i < len; i++) {
      if (pattern[start + i] != pattern[i]) break;
      // matched (i + 1)th charactor
      pi[start + i] = max(pi[start + i], i + 1);
    }
  }
}

vector<int> getPi(string pattern) {  // O(n)
  int len = pattern.size();
  vector<int> pi(len, 0);
  int start = 1;
  int matched = 0;
  while (start + matched < len) {
    // 일치할 때
    if (pattern[start + matched] == pattern[matched]) {
      pi[start + matched] = 1 + matched;
      matched++;
    }
    // 일치하지 않을 때
    else {
      if (matched == 0) {
        start++;
      } else {
        // kmp search
        start += (matched - pi[matched - 1]);
        matched = pi[matched - 1];
      }
    }
  }
}

bool kmp(string text, string pattern) {
  int n = text.size();
  int m = pattern.size();
  // start = matched = 0
  int start = 0;
  int matched = 0;
  vector<int> pi = get_pi(text);
  while (start <= n - m) {
    // matched text's charactor and pattern's charactor
    if (matched < m && text[start + matched] == pattern[matched]) {
      matched++;
      // add answer(correct exactly)
      if (matched == m) {
        return true;
      }
    }
    // fail to search
    else {
      // exception: continue in text charactor if matched equals zero
      if (matched == 0) {
        start++;
      } else {
        start += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }
  return false;
}
