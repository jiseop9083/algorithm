#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

map<char, int> dna;

class Trie {
 public:
  int terminal;
  vector<int> output;
  Trie* fail;
  Trie* node[4];

  Trie() {
    for (int i = 0; i < 4; i++) {
      node[i] = NULL;
    }
  }

  ~Trie() {
    for (int i = 0; i < 4; i++) {
      if (node[i] != NULL) {
        delete node[i];
        node[i] = NULL;
      }
    }
  }

  void insert(string word, int idx) {
    if (idx == word.size()) {
      terminal = -1;
      return;
    }
    int next = dna[word[idx]];
    if (node[next] == NULL) node[next] = new Trie();
    node[next]->insert(word, idx + 1);
  }
};

void makefail(Trie* root) {
  queue<Trie*> q;
  root->fail = root;
  q.push(root);
  while (!q.empty()) {
    Trie* current = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      Trie* next = current->node[i];
      if (!next) continue;
      if (current == root)
        next->fail = root;
      else {
        Trie* fa = current->fail;
        while ((fa != root && fa->node[i] == NULL)) {
          fa = fa->fail;
        }
        if (fa->node[i]) fa = fa->node[i];
        next->fail = fa;
      }
      next->output = next->fail->output;
      if (next->terminal == -1) next->output.push_back(next->terminal);
      q.push(next);
    }
  }
}

vector<pair<int, int>> ahoCorasick(string& s, Trie* root) {
  vector<pair<int, int>> ret;
  Trie* state = root;
  for (int i = 0; i < s.size(); i++) {
    int chr = dna[s[i]];
    while (state != root && state->node[chr] == NULL) state = state->fail;
    if (state->node[chr]) state = state->node[chr];
    for (int j = 0; j < state->output.size(); j++)
      ret.push_back({i, state->output[j]});
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  dna['G'] = 0;
  dna['C'] = 1;
  dna['A'] = 2;
  dna['T'] = 3;
  for (int test = 0; test < T; test++) {
    int n, m;
    cin >> n >> m;
    string arr;
    string marker;
    cin >> arr >> marker;
    Trie* root = new Trie();
    root->insert(marker, 0);
    for (int i = 0; i < marker.size(); i++) {
      for (int j = i + 1; j <= marker.size(); j++) {
        reverse(marker.begin() + i, marker.begin() + j);
        root->insert(marker, 0);
        reverse(marker.begin() + i, marker.begin() + j);
      }
    }

    makefail(root);
    cout << ahoCorasick(arr, root).size() << "\n";
    delete root;
  }
  return 0;
}