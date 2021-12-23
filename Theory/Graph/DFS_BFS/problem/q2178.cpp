//���� 2178�� �̷� Ž��
//bfs����ϴ� ���� �ּڰ��� ã�µ� �����ϴ�.
//pair�� ��ǥ�� ǥ������.

#include <cstdio>
#include <queue>
using namespace std;
int miro[105][105];
int visit[105][105];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;


void bfs() {//y,x
	queue<pair<int, int>>q;
	q.push(make_pair(0, 0));
	visit[0][0] = 1;
	miro[0][0] = 2;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;		
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (miro[ny][nx] == 1 &&(nx >= 0 || nx < m || ny >= 0 || ny < n) && (visit[ny][nx] == 0 || visit[ny][nx] > visit[y][x]) + 1) {
				q.push({ ny, nx });
				visit[ny][nx] = visit[y][x] + 1;
				miro[ny][nx] = 2;
			}
		}
	}
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &miro[i][j]);
			visit[i][j] = 0;
		}
	}
	bfs();
	printf("%d", visit[n-1][m-1]);
	return 0;
}