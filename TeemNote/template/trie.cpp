#include <iostream>
#include <string>
using namespace std;

class Trie {
public:
	//귀찮으니 그냥 public으로 함
	//알파벳은 26개이므로
	Trie* child[26];
	//종료 노드 여부
	bool terminal;


	Trie() : terminal(false) {
		for (int i = 0; i < 26; i++) {
			//NULL은 문자가 없음을 뜻함
			child[i] = NULL;
		}
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (child[i] != NULL) {
				delete child[i];
				//안전하게
				child[i] = NULL;
			}
		}
	}

	int tonum(char c) {
		return tolower(c) - 'a';
	}

	//이 노드를 루트로 하는 트라이에 문자열을 추가
	void insert(const char* word) {
		//문자열이 끝나면 종료
		if (*word == '\0') {
			terminal = true;
			return;
		}

		int next = tonum(*word);
		//자식노드가 없을 때 > 생성
		if (child[next] == NULL) {
			child[next] = new Trie();
		}
		//다음 노드
		child[next]->insert(word + 1);
	}

	//이 노드를 루트로 하는 트라이에 문자열과 대응하는 노드를 찾음
	//없으면 NULL을 리턴
	Trie* find(const char* word) {
		if (*word == '\0') return this;
		int next = tonum(*word);
		if (child[next] == NULL) return NULL;
		return child[next]->find(word + 1);
	}
};

class Trie {
public:
	//귀찮으니 그냥 public으로 함
	//알파벳 소문자는 26개이므로
	Trie* node[26];
	//종료노드인지 여부
	bool terminal;

	Trie() : terminal(false) {
		for (int i = 0; i < 26; i++) {
			//NULL은 문자가 없음을 뜻함
			node[i] = NULL;
		}
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (node[i] != NULL) {
				delete node[i];
				//안전하게 제거
				node[i] = NULL;
			}
		}
	}

	//문자를 숫자로 바꿈, 지금은 문자가 소문자밖에 없음을 가정
	int tonum(char c) {
		return (int)(c - 'a');
	}

	//이 노드를 루트로 하는 트라이에 문자열을 추가
	void insert(const string& word) {
		//pNode는 현재 노드
		Trie* pNode = this;
		for (int i = 0; i < word.size(); i++) {
			//다음 문자의 index
			int index = tonum(word[i]);
			//다음 노드가 없으면
			if (pNode->node[i] == NULL) {
				pNode->node[i] = new Trie();
			}
			//노드 이동
			pNode = pNode->node[i];
		}
		//종료노드임을 체크
		pNode->terminal = true;
	}

	//이 노드를 루트로 하는 트라이에 문자열과 대응하는 노드를 찾음
	//없으면 false을 리턴
	bool find(const string& word, int deep) {
		//찾는 문자열의 마지막
		if (word.size() == deep) {
			//찾는 문자열이 있으면
			if (this->terminal == true) {
				return true;
			}
			return false;
		}
		int next = tonum(word[deep]);
		//더 이상의 노드가 없으면
		if (node[next] == NULL) {
			return false;
		}
		//다음노드로
		return node[next]->find(word, deep + 1);
	}
		
};