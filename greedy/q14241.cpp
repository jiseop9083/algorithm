//백준 14241번 슬라임 합치기

#include <iostream>
#include <queue>
using namespace std;

int n;
int an;
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	while (pq.size() >= 2) {
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		an += first * second;
		pq.push(first + second);
	}
	cout << an;
	return 0;
}
