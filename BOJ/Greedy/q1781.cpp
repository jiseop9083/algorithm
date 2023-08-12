#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
pair<int, int> num[200005];
int n;

bool com(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
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
  int day = 1;
  for (int i = 0; i < n; i++) {
    pq.push(-num[i].second);
    if (num[i].first < day) {
      pq.pop();
    } else {
      day++;
    }
  }
  int answer = 0;
  while (!pq.empty()) {
    answer += -pq.top();

    pq.pop();
  }
  cout << answer;
  return 0;
}