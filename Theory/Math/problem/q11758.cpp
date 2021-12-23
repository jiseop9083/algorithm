//백준 11758번 CCW
//CCW:counter clock wise
//세점을 차례로 이었을 때 시계방향이냐? 반시계방향이냐?

#include <cstdio>

int x1, x2, x3, y1, y2, y3;

int main() {
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);
	int an = x1 * (y2 - y3) - (y1 * (x2 - x3)) + (x2 * y3) - (x3 * y2);
	if (an > 0) {
		printf("1");
	}
	else if (an < 0) {
		printf("-1");
	}
	else {
		printf("0");
	}
	return 0;
}