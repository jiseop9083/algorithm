#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int ALPHABETS = 26;

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

  void insert(string word, int idx) {
    if (idx == word.size()) {
      terminal = -1;
      return;
    }

    int next = word[idx] - 'a';
    if (children[next] == NULL) {
      children[next] = new TrieNode();
    }
    children[next]->insert(word, idx + 1);
  }
};

void computeFail(TrieNode* root) {
  queue<TrieNode*> q;
  root->fail = root;
  q.push(root);
  while (!q.empty()) {
    TrieNode* here = q.front();
    q.pop();
    for (int edge = 0; edge < 26; edge++) {
      TrieNode* next = here->children[edge];
      if (!next) continue;
      if (here == root)
        next->fail = root;
      else {
        TrieNode* t = here->fail;
        while (t != root && t->children[edge] == NULL) {
          t = t->fail;
        }
        if (t->children[edge]) t = t->children[edge];
        next->fail = t;
      }

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
    int chr = s[i] - 'a';
    while (state != root && state->children[chr] == NULL) state = state->fail;
    if (state->children[chr]) state = state->children[chr];
    for (int j = 0; j < state->output.size(); j++)
      ret.push_back({i, state->output[j]});
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q;
  vector<string> arr;
  string s;
  TrieNode* root = new TrieNode;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    root->insert(t, 0);
  }

  computeFail(root);
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> s;
    if (!ahoCorasick(s, root).empty()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}