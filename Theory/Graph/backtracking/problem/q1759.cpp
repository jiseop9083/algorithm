//백준 1759번 암호 만들기
//조건은 자음 2개이상, 모음 한 개 이상이면 출력 > 백트랙킹

#include <cstdio>
#include <algorithm>
using namespace std;
char alphabet[16];
int sol[16];
int l, c;
int num = 0;

void backtracking(int depth) {
	if (depth == c) {
		int vowel = 0;
		int consonant = 0;
		char print[16];
		for (int i = 0; i < c; i++) {
			//printf("%c\n", alphabet[i]);
			if (sol[i] == 1) {
				print[(vowel + consonant)] = alphabet[i];

				if (alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' || alphabet[i] == 'o' || alphabet[i] == 'u') {
					vowel++;
				}
				else consonant++;
			}
		}
		if (consonant + vowel == l && consonant >= 2 && vowel >= 1) {
			sort(print, print + l);
			for (int j = 0; j < l; j++) {
				printf("%c", print[j]);
			}
			printf("\n");
		}
		return;

	}
	for (int i = 1; i >= 0; i--) {
		sol[depth] = i;
		backtracking(depth + 1);
	}
}

int main() {
	scanf("%d %d", &l, &c);
	for (int i = 0; i < c; i++) {
		scanf(" %c", &alphabet[i]);
	}
	sort(alphabet, alphabet + c);
	backtracking(0);
	return 0;
}