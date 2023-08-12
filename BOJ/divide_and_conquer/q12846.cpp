#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int n;
int height[100005];
stack<int> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> height[i];
  }
  height[n + 1] = 0;
  s.push(0);
  int answer = 0;
  for (int i = 1; i <= n + 1; i++) {
    while (!s.empty() && height[s.top()] > height[i]) {
      int chk = s.top();
      s.pop();
      answer = max(answer, height[chk] * (i - s.top() - 1));
    }
    s.push(i);
  }
  cout << answer;
  return 0;
}
