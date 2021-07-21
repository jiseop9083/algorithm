#include <iostream>
#include <string>
using namespace std;

class Trie {
public:
	//�������� �׳� public���� ��
	//���ĺ��� 26���̹Ƿ�
	Trie* child[26];
	//���� ��� ����
	bool terminal;


	Trie() : terminal(false) {
		for (int i = 0; i < 26; i++) {
			//NULL�� ���ڰ� ������ ����
			child[i] = NULL;
		}
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (child[i] != NULL) {
				delete child[i];
				//�����ϰ�
				child[i] = NULL;
			}
		}
	}

	int tonum(char c) {
		return tolower(c) - 'a';
	}

	//�� ��带 ��Ʈ�� �ϴ� Ʈ���̿� ���ڿ��� �߰�
	void insert(const char* word) {
		//���ڿ��� ������ ����
		if (*word == '\0') {
			terminal = true;
			return;
		}

		int next = tonum(*word);
		//�ڽĳ�尡 ���� �� > ����
		if (child[next] == NULL) {
			child[next] = new Trie();
		}
		//���� ���
		child[next]->insert(word + 1);
	}

	//�� ��带 ��Ʈ�� �ϴ� Ʈ���̿� ���ڿ��� �����ϴ� ��带 ã��
	//������ NULL�� ����
	Trie* find(const char* word) {
		if (*word == '\0') return this;
		int next = tonum(*word);
		if (child[next] == NULL) return NULL;
		return child[next]->find(word + 1);
	}
};

class Trie {
public:
	//�������� �׳� public���� ��
	//���ĺ� �ҹ��ڴ� 26���̹Ƿ�
	Trie* node[26];
	//���������� ����
	bool terminal;

	Trie() : terminal(false) {
		for (int i = 0; i < 26; i++) {
			//NULL�� ���ڰ� ������ ����
			node[i] = NULL;
		}
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (node[i] != NULL) {
				delete node[i];
				//�����ϰ� ����
				node[i] = NULL;
			}
		}
	}

	//���ڸ� ���ڷ� �ٲ�, ������ ���ڰ� �ҹ��ڹۿ� ������ ����
	int tonum(char c) {
		return (int)(c - 'a');
	}

	//�� ��带 ��Ʈ�� �ϴ� Ʈ���̿� ���ڿ��� �߰�
	void insert(const string& word) {
		//pNode�� ���� ���
		Trie* pNode = this;
		for (int i = 0; i < word.size(); i++) {
			//���� ������ index
			int index = tonum(word[i]);
			//���� ��尡 ������
			if (pNode->node[i] == NULL) {
				pNode->node[i] = new Trie();
			}
			//��� �̵�
			pNode = pNode->node[i];
		}
		//���������� üũ
		pNode->terminal = true;
	}

	//�� ��带 ��Ʈ�� �ϴ� Ʈ���̿� ���ڿ��� �����ϴ� ��带 ã��
	//������ false�� ����
	bool find(const string& word, int deep) {
		//ã�� ���ڿ��� ������
		if (word.size() == deep) {
			//ã�� ���ڿ��� ������
			if (this->terminal == true) {
				return true;
			}
			return false;
		}
		int next = tonum(word[deep]);
		//�� �̻��� ��尡 ������
		if (node[next] == NULL) {
			return false;
		}
		//��������
		return node[next]->find(word, deep + 1);
	}
		
};