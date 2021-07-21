

//기본문제
//백준 11729번 하노이 탑 이동 순서
//백준 1074번 Z
//백준 1725번 히스토그램

#include <iostream>
using namespace std;

int arr[10000];

void dosomething() {
	return;
}

//분할정복
//큰 문제를 작은 문제로 나누어 해결
//큰 문제와 작은 문제해결 방식이 같다!!!
int dc(int start, int end) {
	if (start > end) {
		return;
	}
	int mid = (start + end) / 2;
	//문제나누기(divide)
	dc(start, mid);
	dc(mid + 1, end);

	//작은 문제 두개 합치기(conquer)
	dosomething();
	return;
}