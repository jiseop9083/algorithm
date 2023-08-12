#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie {
 public:
  vector<Trie*> node;
  bool isTerminate;
  string word;
  void insert(vector<string> words, int deep);
  void find(int deep);
  Trie() : isTerminate(true), word("") {
    for (Trie* i : node) {
      i = NULL;
    }
  }

  ~Trie() {
    while (!node.empty()) {
      node.pop_back();
    }
  }
};

bool com(Trie* a, Trie* b) { return a->word < b->word; }

void Trie::insert(vector<string> words, int deep) {
  if (deep == words.size()) {
    return;
  }
  for (Trie* i : node) {
    if (i->word == words[deep]) {
      return i->insert(words, deep + 1);
    }
  }
  isTerminate = false;
  node.push_back(new Trie());
  node.back()->word = words[deep];
  return node.back()->insert(words, deep + 1);
}

void Trie::find(int deep) {
  Trie* pNode = this;
  if (word != "") {
    for (int j = 1; j < deep; j++) cout << "--";
    cout << word << "\n";
  }
  sort(node.begin(), node.end(), com);
  for (Trie* i : node) {
    i->find(deep + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  string arr;
  cin >> n;
  Trie trie;
  for (int i = 0; i < n; i++) {
    cin >> k;
    vector<string> arr;
    for (int j = 0; j < k; j++) {
      string s;
      cin >> s;
      arr.push_back(s);
    }
    trie.insert(arr, 0);
  }
  trie.find(0);
  return 0;
}