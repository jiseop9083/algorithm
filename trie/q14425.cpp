//백준 14425번 문자열 집합

#include <iostream>
#include <string>
using namespace std;

class Trie {
public:
	Trie* node[26];
	bool terminal;

	Trie() : terminal(false) {
		for (int i = 0; i < 26; i++) {
			node[i] = NULL;
		}
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (node[i] != NULL) {
				delete node[i];
				node[i] = NULL;
			}
		}
	}

	int tonum(char c) {
		return (int)(c - 'a');
	}

	void insert(const string& word) {
		Trie* pNode = this;
		for (int i = 0; i < word.size(); i++) {
			int index = tonum(word[i]);
			if (pNode->node[index] == NULL) {
				pNode->node[index] = new Trie();
			}
			pNode = pNode->node[index];
		}
		pNode->terminal = true;
	}

	bool find(const string& word, int deep) {
		if (word.size() == deep) {
			if (this->terminal == true) {
				return true;
			}
			return false;
		}
		int next = tonum(word[deep]);
		if (node[next] == NULL) {
			return false;
		}
		return node[next]->find(word, deep + 1);
	}

};

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Trie tri;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string arr;
		cin >> arr;
		tri.insert(arr);
	}
	int an = 0;
	for (int i = 0; i < m; i++) {
		string arr;
		cin >> arr;
		if (tri.find(arr, 0)) {
			an++;
		}
	}
	cout << an;
	return 0;
}
