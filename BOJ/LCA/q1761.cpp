#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int depth[50005];
pair<int, int> ac[50005][20];
vector<pair<int, int>> ve[50005];
int mlevel;

void getTree(int here, int parent, int cost) {
  depth[here] = depth[parent] + 1;
  ac[here][0] = {parent, cost};
  mlevel = 18;
  for (int i = 1; i <= mlevel; i++) {
    int temp = ac[here][i - 1].first;
    ac[here][i] = {ac[temp][i - 1].first,
                   ac[temp][i - 1].second + ac[here][i - 1].second};
  }

  for (pair<int, int> i : ve[here]) {
    if (i.first != parent) getTree(i.first, here, i.second);
  }
}

void swap(int& a, int& b) {
  int t = a;
  a = b;
  b = t;
}

int getLCA(int a, int b) {
  int ret = 0;
  if (depth[a] != depth[b]) {
    if (depth[a] > depth[b]) swap(a, b);
    for (int i = mlevel; i >= 0; i--) {
      if (depth[a] <= depth[ac[b][i].first]) {
        ret += ac[b][i].second;
        b = ac[b][i].first;
      }
    }
  }
  int lca = a;
  if (a != b) {
    for (int i = mlevel; i >= 0; i--) {
      if (ac[a][i].first != ac[b][i].first) {
        ret += ac[a][i].second;
        ret += ac[b][i].second;
        a = ac[a][i].first;
        b = ac[b][i].first;
      }
      lca = ac[a][i].first;
    }
    ret += ac[a][0].second;
    ret += ac[b][0].second;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(ac, 0, sizeof(ac));
  int n, m;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    ve[a].push_back({b, c});
    ve[b].push_back({a, c});
  }
  depth[0] = -1;
  getTree(1, 0, 0);
  cin >> m;
  /*for (int i = 1; i <= n; i++) {
     for (int j = 0; j < 5; j++) {
       cout << ac[i][j].first << " " << ac[i][j].second << " ";
     }
     cout << "\n";
   }*/
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    cout << getLCA(a, b) << "\n";
  }
  return 0;
}