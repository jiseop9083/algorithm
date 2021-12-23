#include <iostream>
#include <string>
using namespace std;

int pi[200005];

void get_pi(string pattern) {
	int len = pattern.size();
	//start = 0에서 시작하면 바로 matched = len이 된다.
	//pi[0] = 0으로 처리하자
	pi[0] = 0;
	//pi[0] = 0이므로 1부터 탐색
	int start = 1;
	int matched = 0;
	while (start + matched < len) {
		//일치할 때
		if (pattern[start + matched] == pattern[matched]) {
			pi[start + matched] = 1 + matched;
			matched++;
		}
		//일치하지 않을 때
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
	//검색을 시작하는 위치
	int start = 0;
	//pattern과 일치하는 문자열의 길이
	int matched = 0;
	while (start <= n - m) {
		//검색에 성공했을 때
		if (matched < m && text[start + matched] == pattern[matched]) {
			matched++;
			//정답 추가(완벽히 일치할 때)
			if (matched == m) {
				//정답
				return true;
			}
		}
		//검색에 실패했을때
		else {
			//예외: 처음에는 다음 칸에서 계속
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



	

	
