#include <iostream>
#include <string>
using namespace std;

int pi[200005];

void get_pi(string pattern) {
	int len = pattern.size();
	//start = 0���� �����ϸ� �ٷ� matched = len�� �ȴ�.
	//pi[0] = 0���� ó������
	pi[0] = 0;
	//pi[0] = 0�̹Ƿ� 1���� Ž��
	int start = 1;
	int matched = 0;
	while (start + matched < len) {
		//��ġ�� ��
		if (pattern[start + matched] == pattern[matched]) {
			pi[start + matched] = 1 + matched;
			matched++;
		}
		//��ġ���� ���� ��
		else {
			if (matched == 0) {
				start++;
			}
			else {
				start += (matched - pi[matched - 1]);
				matched = pi[matched - 1];
			}
		}
	}
}

bool kmp(string text, string pattern) {
	int n = text.size();
	int m = pattern.size();
	//�˻��� �����ϴ� ��ġ
	int start = 0;
	//pattern�� ��ġ�ϴ� ���ڿ��� ����
	int matched = 0;
	while (start <= n - m) {
		//�˻��� �������� ��
		if (matched < m && text[start + matched] == pattern[matched]) {
			matched++;
			//���� �߰�(�Ϻ��� ��ġ�� ��)
			if (matched == m) {
				//����
				return true;
			}
		}
		//�˻��� ����������
		else {
			//����: ó������ ���� ĭ���� ���
			if (matched == 0) {
				start++;
			}
			else {
				start += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return false;
}



	

	
