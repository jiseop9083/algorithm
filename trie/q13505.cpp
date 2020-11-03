//백준 13505번 두 수 XOR

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int an = 0;
int num[100005];
int temp = 0;
int word[35];

class Trie {
public:
	Trie* child[2];
	bool terminal;

	Trie() : terminal(false) {
		for (int i = 0; i < 3; i++) {
			child[i] = NULL;
		}
	}

	~Trie() {
		for (int i = 0; i < 3; i++) {
			if (child[i] != NULL) {
				delete child[i];
				child[i] = NULL;
			}
		}
	}

	void insert(int* num, int digit) {
		if (digit < 0) {
			terminal = true;
			return;
		}
		else {
			int next = num[digit];
			if (child[next] == NULL) {
				child[next] = new Trie();
			}
			child[next]->insert(num, digit - 1);
		}
	}

	int find(int* num, int digit) {
		if (digit < 0) {
			return 0;
		}
		int next = (num[digit] + 1) % 2;
		if (child[next] != NULL) {
			return child[next]->find(num, digit -1) + pow(2, digit);
		}
		next = num[digit];
		if(child[next] != NULL) {
			return child[next]->find(num, digit - 1);
		}
	}
};

bool com(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	Trie tri;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num[i] = a;
		for(int i = 0; i < 31; i++){
			word[i] = a % 2;
			a /= 2;
		}
		tri.insert(word, 30);
	}
	sort(num, num + n, com);
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		int a = num[i];
		for (int i = 0; i < 31; i++) {
			word[i] = a % 2;
			a /= 2;
		}
		int b = tri.find(word, 30);
		an = max(an, b);
	}
	cout << an;
	return 0;
}
