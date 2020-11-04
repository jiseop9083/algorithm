//백준 9202번 Boggle

#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int dx[8] = { 0,0, 1, -1 , 1, 1, -1 ,-1 };
int dy[8] = { 1, -1, 0,0 , 1, -1, 1, -1 };
const int table[9] = { 0, 0, 0,1, 1,2,3,5,11 };
bool check[4][4];
set<string> se;
string board[4];
string an;
int w, b;
int score = 0;
int ma = 0;

class Trie {
public:
	Trie* child[26];
	bool terminal;

	Trie() : terminal(false) {
		for (int i = 0; i < 26; i++) {
			child[i] = NULL;
		}
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (child[i] != NULL) {
				delete child[i];
				child[i] = NULL;
			}
		}
	}

	int tonum(char c) {
		return (int)(c - 'A');
	}

	void insert(const string& word) {
		Trie* pNode = this;
		for (int i = 0; i < word.size(); i++) {
			int index = tonum(word[i]);
			if (pNode->child[index] == NULL) {
				pNode->child[index] = new Trie();
			}
			pNode = pNode->child[index];
		}
		pNode->terminal = true;
	}

	void find(string word, int y, int x) {
		if (word.size() == 8) {
			return;
		}
		check[y][x] = true;
		word += board[y][x];

		Trie* pNode = this->child[tonum(board[y][x])];
		if (pNode == NULL) {
			check[y][x] = false;
			return;
		}
		if (pNode->terminal == true) {
			se.insert(word);
		}
		for (int i = 0; i < 8; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || xx >= 4 || yy < 0 || yy >= 4 || check[yy][xx]) {
				continue;
			}
			pNode->find(word, yy, xx);
		}
		check[y][x] = false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Trie tri;
	memset(check, false, sizeof(check));
	cin >> w;
	for (int i = 0; i < w; i++) {
		string arr;
		cin >> arr;
		tri.insert(arr);
	}
	cin >> b;
	for (int test = 0; test < b; test++) {
		score = 0;
		ma = 0;
		for (int i = 1; i <= 8; i++) {
			se.clear();
		}
		for (int i = 0; i < 4; i++) {
			cin >> board[i];
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				string arr = "";
				tri.find(arr, i, j);
			}
		}
		string an;
		set<string>::iterator iter;
		for (iter = se.begin(); iter != se.end(); iter++) {
			if (ma < (int)(iter->size())) {
				ma = (int)(iter->size());
				an = *iter;
			}
			score += table[iter->size()];
		}
		cout << score << " " << an << " " << se.size() << "\n";

	}
	return 0;
}
