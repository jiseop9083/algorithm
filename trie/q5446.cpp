//백준 5446번 용량 부족

#include <iostream>
using namespace std;

int an = 0;
int t;
int n, m;

class Trie {
public:
	Trie* child[65];
	bool terminal;
	bool canRemove;

	Trie() : terminal(false), canRemove(false) {
		for (int i = 0; i < 65; i++) {
			child[i] = NULL;
		}
	}

	~Trie() {
		for (int i = 0; i < 65; i++) {
			if (child[i] != NULL) {
				delete child[i];
				child[i] = NULL;
			}
		}
	}
	
	int tonum(char c) {
		if ('a' <= c && c <= 'z') {
			return (int)(c - 'a');
		}
		else if ('A' <= c && c <= 'Z') {
			return (int)(c - 'A') + 26;
		}
		else if ('0' <= c && c <= '9') {
			return (int)(c - '0') + 52;
		}
		else if (c == '.') {
			return 62;
		}
	}

	void insert(string word, bool possible) {
		Trie* pNode = this;
		for (int i = 0; i < word.size(); i++) {
			int index = tonum(word[i]);
			pNode->canRemove = possible;
			if (!pNode->child[index]) {
				pNode->child[index] = new Trie();
			}
			pNode = pNode->child[index];
		}
		pNode->canRemove = possible;
		pNode->terminal = true;
	}

	void find() {
		if (canRemove == true) {
			an++; 
			return;
		}
		else if (terminal == true) {
			an++;
		}
		for (int i = 0; i < 65; i++) {
			if (child[i] != NULL) {
				child[i]->find();
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> t;
	for (int test = 0; test < t; test++) {
		Trie tri;
		an = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string arr;
			cin >> arr;
			tri.insert(arr, true);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			string arr;
			cin >> arr;
			tri.insert(arr, false);
		}
		tri.find();
		cout << an - m << "\n";
	}
	return 0;
}
