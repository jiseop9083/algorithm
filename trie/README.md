# Trie(트라이)
## 트라이란?
- 문자열을 비교하는데 있어서 특화된 자료구조이다.
- 특히, 문자열을 저장하고 효율적으로 탐색할 수 있다.
- 제일 긴 문자열의 길이를 L, 문자열의 개수를 M이라고 할 때
- 트라이 생성시 시간복잡도는 ```O(M*L)``` (문자열 M개에 대해서 삽입하는데 L만큼 걸림 > O(M*L))
- 탐색시 시간복잡도: O(L) (가장 긴 문자열의 길이만큼만 탐색)
- 다만, 포인터들을 배열로 모두 저장하고 있다는 점에서 저장 공간의 크기가 크다는 단점을 가진다.

## 트라이의 구조(Template)
- 바로 코드를 보자
``` 
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
```

---

## 문제 풀자
### 백준 14425번 문자열 집합

<https://www.acmicpc.net/problem/14425>
- 전형적인 트라이를 묻는 기본 문제이다.
- 굉장히 간단하므로 빠르게 넘어가자   ~사실 위의 코드를 붙여넣고 main만 구현하면 된다~


### 백준 9202번 Boggle
