//백준 11729번 하노이 탑 이동 순서

#include <iostream>
using namespace std;

int n;

void slove(int deep, int start, int mid, int end) {
    if (deep == 0) {
        return;
    }
    slove(deep - 1, start, end, mid);
    cout << start << " " << end << "\n";
    slove(deep - 1, mid, start, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n;
    int an = 1;
    for (int i = 0; i < n; i++) {
        an *= 2;
    }
    cout << an - 1 << "\n";
    slove(n, 1, 2, 3);
	return 0;
}
