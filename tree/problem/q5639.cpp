//백준 5639번 이진 검색 트리
//이진 트리를 익히자
//전위: 루트, 왼쪽 노드 전부, 오른쪽 노드 전부
//중위: 왼쪽 노드 전부, 루트, 오른쪽 노드 전부
//후위: 왼쪽 노트 전부, 오른쪽 노드 전부, 루트

#include <cstdio>
using namespace std;

int node[10005];

void search(int start, int en) {
	if (start > en) {
		return;
	}
	if (start == en) {
		printf("%d\n", node[start]);
		return;
	}
	int i = start + 1;
	for(i = start + 1; i <= en; i++){
		if (node[i] > node[start]) {
			break;
		}
	}
	search(start + 1, i - 1);
	search(i, en);
	printf("%d\n", node[start]);
}

int main() {
	int i = 0;
	while (scanf("%d", &node[i]) != EOF) {
		i++;
	}
	search(0, i-1);
		
	return 0;
}