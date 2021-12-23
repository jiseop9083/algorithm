//백준 6603번 로또
//nCk=nC(n-k)임을 이용하자!

#include <stdio.h>

int exclude[10];
int num[14];
int k;
int stop = 1;

void backtracking(int picknum) {
	if (k == picknum) {
		int ex = 0;
		for (int i = 0; i < stop; i++) {
			if (exclude[ex] == num[i]) {
				ex++;
				continue;
			}
			else {
				printf("%d ", num[i]);
				continue;
			}
		}
		printf("\n");
		return;
	}
	if (picknum > 0) {
		for (int i = stop - 1; num[i] >= exclude[picknum - 1]; i--) {
			if (exclude[picknum - 1] == num[i]) {
				continue;
			}
			exclude[picknum] = num[i];
			backtracking(picknum + 1);
		}
	}
	else {
		for (int i = stop - 1; i >= 0; i--) {
			exclude[picknum] = num[i];
			backtracking(picknum + 1);
		}
	}
}

int main() {
	
	while (stop != 0 ) {
		scanf("%d", &stop);
		k = stop - 6;
		for (int i = 0; i < stop; i++) {
			scanf("%d", &num[i]);
			exclude[i] = 0;
		}
		backtracking(0);
		printf("\n");
	}
}