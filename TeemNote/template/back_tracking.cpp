//백트렉킹
//기본적으로 dfs(완전 탐색)
//단, 가능성이 없는 경우는 잘라내자
//경우의 수가 다양할 때 사용가능


//기본 문제
//백준 9663번 N -Queen
//백준 N과 M시리즈
//백준 2580번 스도쿠

#include <iostream>
using namespace std;

int solution[100000];
int n;

bool IsOK();
void Dosomething();

void back(int deep) {
	if (deep == n) {
		//최적해인지 검사
		//for문에서 미리 해봐도 괜찮다
		if (IsOK()) {
			Dosomething();
		}
		return;
	}

	for (int i = 0; i <= 1; i++) {
		//여기서 검사해도 됨
		if (IsOK()) {
			solution[deep] = i;
			//자식노드로 이동
			back(deep + 1);
		}
	}
}