#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
 public:
  int terminal;
  TrieNode* fail;
  vector<int> output;
  TrieNode* children[26];
  TrieNode() {
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
  }
  ~TrieNode() {
    for (int i = 0; i < 26; i++) {
      if (children[i] != NULL) {
        delete children[i];
        children[i] = NULL;
      }
    }
  }

  int tonum(char c) { return tolower(c) - 'a'; }

  void insert(char* word) {
    if (*word == '\0') {
      terminal = true;
      return;
    }

    int next = tonum(*word);
    if (children[next] == NULL) {
      children[next] = new TrieNode();
    }
    children[next]->insert(word + 1);
  }
};

void computeFail(TrieNode* root) {
  queue<TrieNode*> q;
  root->fail = root;
  q.push(root);
  while (!q.empty()) {
    TrieNode* here = q.front();
    q.pop();

    // here의 모든 자손에 대해 실패 연경을 계산하고 이들을 큐에 넣음
    for (int edge = 0; edge < 26; ++edge) {
      TrieNode* next = here->children[edge];
      if (!next) continue;
      if (here == root)
        next->fail = root;
      else {
        // 아닌 경우 fail을 참조할 가장 가까운조상을 찾아간다.
        TrieNode* t = here->fail;
        while (t != root && t->children[edge] == NULL) {
          t = t->fail;
        }
        if (t->children[edge]) t = t->children[edge];
        next->fail = t;
      }

      // 이 위치에서 끝나는 바늘 문자열이 있으면 추가한다.
      next->output = next->fail->output;
      if (next->terminal == -1) next->output.push_back(next->terminal);
      q.push(next);
    }
  }
}

vector<pair<int, int>> ahoCorasick(string& s, TrieNode* root) {
  vector<pair<int, int>> ret;
  TrieNode* state = root;
  for (int i = 0; i < s.size(); i++) {
    int chr = (int)(s[i] - 'a');
    // 현재 노드에서 갈 수 없으면 fail계속 따라감
    while (state != root && state->children[chr] == NULL) state = state->fail;
    if (state->children[chr]) state = state->children[chr];
    // 현재 노드에 output이 있으면 찾음
    for (int j = 0; j < state->output.size(); j++)
      ret.push_back({i, state->output[j]});
  }
  return ret;
}