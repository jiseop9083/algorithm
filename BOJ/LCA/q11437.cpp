#include <cmath>
#include <iostream>
#include <vector>
#define MAX_NODE 100001
using namespace std;

// 노드의 레벨
int depth[MAX_NODE];
// ac[x][y] :: x의 2^y번째 조상
int ac[MAX_NODE][20];
vector<int> ve[MAX_NODE];
int mlevel;

void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

// DP(ac)배열 만드는 과정
void getTree(int here, int parent) {
  // here의 깊이는 부모노드깊이 + 1
  depth[here] = depth[parent] + 1;

  // here의 1번째 조상은 부모노드
  ac[here][0] = parent;

  // MAX_NODE에 log2를 씌어 내림을 해준다.
  mlevel = (int)floor(log2(MAX_NODE));

  for (int i = 1; i <= mlevel; i++) {
    // tmp: here의 2^(i-1)번째 조상
    // here의 2^i번째 조상은 tmp의 2^(i-1)번째 조상의 2^(i-1)번째 조상과 같음
    int tmp = ac[here][i - 1];
    ac[here][i] = ac[tmp][i - 1];
  }

  for (int i : ve[here]) {
    int there = i;
    if (there != parent) getTree(there, here);
  }
}

int getLCA(int a, int b) {
  if (depth[a] != depth[b]) {
    if (depth[a] > depth[b]) swap(a, b);
    // depth 맞추기
    for (int i = mlevel; i >= 0; i--) {
      if (depth[a] <= depth[ac[b][i]]) b = ac[b][i];
    }
  }
  int ret = a;
  // 동시에 depth 올려 lca찾기
  if (a != b) {
    for (int i = mlevel; i >= 0; i--) {
      if (ac[a][i] != ac[b][i]) {
        a = ac[a][i];
        b = ac[b][i];
      }
      ret = ac[a][i];
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ve[a].push_back(b);
    ve[b].push_back(a);
  }

  depth[0] = -1;
  getTree(1, 0);
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    cout << getLCA(a, b) << "\n";
  }
  return 0;
}