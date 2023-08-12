#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int in1[200005];
int in2[200005];

vector<int> getPi(vector<int> nums) {
  int len = nums.size();
  int start = 1;
  int matched = 0;
  vector<int> ret(len, 0);
  while (start + matched < len) {
    if (nums[start + matched] == nums[matched]) {
      ret[start + matched] = matched + 1;
      matched++;
    } else {
      if (matched == 0) {
        start++;
      } else {
        start += (matched - ret[matched - 1]);
        matched = ret[matched - 1];
      }
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> v1;
  vector<int> v2;

  for (int i = 0; i < n; i++) cin >> in1[i];
  for (int i = 0; i < n; i++) cin >> in2[i];
  sort(in1, in1 + n);
  sort(in2, in2 + n);
  for (int i = 1; i < n; i++) {
    v1.push_back(in1[i] - in1[i - 1]);
    v2.push_back(in2[i] - in2[i - 1]);
  }
  v1.push_back(in1[0] + 360000 - in1[n - 1]);
  v2.push_back(in2[0] + 360000 - in2[n - 1]);
  vector<int> pi = getPi(v2);
  v1.insert(v1.end(), v1.begin(), v1.end());
  int start = 0;
  int matched = 0;
  while (start <= v1.size() - v2.size()) {
    if (matched < v2.size() && v1[start + matched] == v2[matched]) {
      matched++;
      if (matched == v2.size()) {
        cout << "possible";
        return 0;
      }
    } else {
      if (matched == 0)
        start++;
      else {
        start += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }
  cout << "impossible";
  return 0;
}