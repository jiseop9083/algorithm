//백준 12100번 2048(Easy)
//배열을 이용하여 구하자

#include <cstdio>

int num[5] = { 0,0,0,0,0 }; //이동 횟수
int table[25][25];
int q[25][25];
int n;


void laft() {
	for (int i = 0; i < n; i++) {
		int mem = -1;
		int pos;
		for (int j = 0; j < n; j++) {
			if (table[i][j] == mem) {
				table[i][j] *= 2;
				table[i][pos] = 0;
				mem = -1;
			}
			else if (table[i][j] != 0) {
				mem = table[i][j];
				pos = j;
			}
		}
		int j = 1;
		while (j < n) {
			if (table[i][j] != 0 && table[i][j - 1] == 0) {
				table[i][j - 1] = table[i][j];
				table[i][j] = 0;
				if (j > 1) {
					j--;
				}
			}
			else j++;

		}
	}

}

void right() {
	for (int i = 0; i < n; i++) {
		int mem = -1;
		int pos;
		for (int j = n - 1; j >= 0; j--) {
			if (table[i][j] == mem) {
				table[i][j] *= 2;
				table[i][pos] = 0;
				mem = -1;
			}
			else if (table[i][j] != 0) {
				mem = table[i][j];
				pos = j;
			}
		}
		int j = n - 2;
		while (j>= 0){
			if (table[i][j] != 0 && table[i][j + 1] == 0) {
				table[i][j + 1] = table[i][j];
				table[i][j] = 0;
				if (j < n - 2) {
					j++;
				}
			}
			else j--;
			
		}
	}
}

void top() {
	for (int j = 0; j < n; j++) {
		int mem = -1;
		int pos;
		for (int i = 0; i < n; i++) {
			if (table[i][j] == mem) {
				table[i][j] = 0;
				table[pos][j] *= 2;
				mem = -1;
			}
			else if (table[i][j] != 0) {
			mem = table[i][j];
			pos = i;
			}
		}
		int i = 1;
		while (i < n) {
			if (table[i][j] != 0 && table[i - 1][j] == 0) {
				table[i - 1][j] = table[i][j];
				table[i][j] = 0;
				//printf("%d %d\n", i, j);
				if (i > 1)
					i--;
			}
			else i++;
		}
	}
}

void bottom() {

	for (int j = 0; j < n; j++) {
		int mem = -1;
		int pos;
		for (int i = n - 1; i >= 0; i--) {
			if (table[i][j] == mem) {
				table[i][j] *= 2;
				table[pos][j] = 0;
				mem = -1;
			}
			else if (table[i][j] != 0) {
				mem = table[i][j];
				pos = i;
			}
		}
		int i = n - 2;
		while (i >= 0){
			if (table[i][j] != 0 && table[i + 1][j] == 0) {
				table[i + 1][j] = table[i][j];
				table[i][j] = 0;
				if (i < n - 2) {
					i++;
				}
			}
			else i--;
		}
	}
}


void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
}

int play() {
	int max = 0;
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			table[i][j] = q[i][j];
		}
	}
	right();
	show();
	bottom();
	show();
	laft();
	show();
	top();
	show();*/
	for (int d = 0; d < 4; d++) {
		for(int e = 0; e < 4; e ++){
			for (int a = 0; a < 4; a++) {
				for (int b = 0; b < 4; b++) {
					for (int c = 0; c < 4; c++) {
						num[0] = c;
						num[1] = b;
						num[2] = a;
						num[3] = d;
						num[4] = e;
						for (int i = 0; i < n; i++) {
							for (int j = 0; j < n; j++) {
								table[i][j] = q[i][j];
							}
						}

						for (int k = 0; k < 5; k++) {//1회전

							switch (num[k]) {
								
							case 0:
								bottom();
								break;
							case 1:
								top();
								break;
							case 2:
								right();
								break;
							case 3:
								laft();
								break;
							}
						}

						for (int i = 0; i < n; i++) {
							for (int j = 0; j < n; j++) {
								if (max < table[i][j]) {
									max = table[i][j];
								}
							}
						}

					}
				}

			}
			
		}

	}
	return max;
}

int main() {
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &q[i][j]);
		}
	}
	printf("%d\n", play());

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}*/
	
	return 0;
}