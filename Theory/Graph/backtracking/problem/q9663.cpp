//���� 9663�� N-Queen
//�ִ� n^2���� ��带 ������!
//������ �Ұ����� ��ġ�� ������ ��!
//�� �ٿ� �� �ϳ��� �ʼ�!!

#include <cstdio>
int count = 0;
int board[16][2] = { {-1, -1}, };//(y,x)
int n;

void backtracking(int depth) {//���� ���� ����
	if (depth == n) {
		count++;
		board[depth][0] = -1;
		board[depth][1] = -1;
		return;
		
	}
	for (int i = 0; i < n; i++) {//x
		if (depth == 0) {
			board[depth][0] = depth;
			board[depth][1] = i;
			backtracking(depth + 1);
		}
		else {
			int j = 0;
			for (int k = 0; k < depth; k++) {
				if (board[k][0] < 0) break;
				else if (board[k][1] == i || board[k][0] - board[k][1] == depth - i || board[k][0] + board[k][1] == i + depth) {
					j = 1;
					break;
				}
			}

			if (j == 0) {
				board[depth][0] = depth;
				board[depth][1] = i;
				//printf("%d %d\n", depth, board[depth][1]);
				backtracking(depth + 1);
			}
		}
	}

	for (int i = 15; i > 0; i--) {
		if (board[i][0] >= 0 && board[i][1] >= 0) {
			board[i][0] = -1;
			board[i][1] = -1;
			return;
		}
	}
	
}



int main() {
	scanf("%d", &n);
	backtracking(0);
	printf("%d", count);
	return 0;
}