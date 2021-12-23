//백준 1019번 책 페이지
//잘 생각해보자
#include <iostream>
#include <cstring>
using namespace std;

int n;
long long an[10];

void add(long long deep, int num) {
	while (num > 0) {
		an[num % 10]+= deep;
		num = num / 10;
	}
}

void sum(long long deep, int start, int end) {
	while (start != end && start % 10 != 0) {
		add(deep, start);
		start++;
	}
	while (start != end && end % 10 != 9) {
		add(deep, end);
		end--;
	}
	if (start == end) {
		add(deep, start);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		an[i] += deep * (long long)((end / 10) - (start / 10) + 1);
	}
	sum(deep * 10, (start / 10), (end / 10));
}

int main() {
	cin >> n;
	memset(an, 0, sizeof(an));
	sum(1, 1, n);
	
	for (int i = 0; i <= 9; i++) {
		cout << an[i] << " ";
	}
	return 0;
}