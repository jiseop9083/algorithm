//백준 107386번 선분 교차1

#include <iostream>
using namespace std;

int ccw(long long x1, long long x2, long long x3, long long y1, long long y2, long long y3) {
	long long an = x1 * (y2 - y3) - (y1 * (x2 - x3)) + (x2 * y3) - (x3 * y2);
	if (an > 0) {
		return 1;
	}
	else if (an < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

long long dis(long long x1, long long y1, long long x2, long long y2) {
	return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
}

int main() {
	long long x1, y1, x2, y2;
	long long x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	int a = ccw(x1, x2, x3, y1, y2, y3);
	int b = ccw(x1, x2, x4, y1, y2, y4);
	int c = ccw(x3, x4, x1, y3, y4, y1);
	int d = ccw(x3, x4, x2, y3, y4, y2);
	if (a * b <= 0 && c * d <= 0) {
		if (a == 0 && b == 0 && c == 0 && d == 0) {
			if ((dis(x1, y1, x2, y2) >= dis(x3, y3, x2, y2) && dis(x1, y1, x2, y2) >= dis(x1, y1, x3, y3)) ||
				(dis(x1, y1, x2, y2) >= dis(x4, y4, x2, y2) && dis(x1, y1, x2, y2) >= dis(x1, y1, x4, y4))) {
				cout << "0";
				return 0;
			}
		}
		cout << "1";
	}
	else {
		cout << "0";
	}
	return 0;
}
