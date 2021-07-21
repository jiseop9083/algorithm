//disjoint set (디스조인트 셋)
//서로 중복되지 않는 부분 집합들로 나뉘진 원소를 저장하는 자료구조


//기본문제

//백준 1197번 최소 스패닝 트리

#include <iostream>
#include <queue>
using namespace std;

class Disjoint{
public:
	int ele[10000];
	
	Disjoint(int t) {
		for (int i = 0; i < t; i++) {
			//자기자신으로 초기화
			ele[i] = i;
		}
	}

	int find(int node) {
		//내가 root일 경우
		if (node == ele[node]) {
			return node;
		}
		//부모의 노드를 찾고 저장
		return node = find(ele[node]);
	}

	int sum(int node_a, int node_b) {
		int root_a = find(node_a);
		int root_b = find(node_b);

		//a집합에 b집합을 추가
		ele[root_b] = root_a;
	}
};

//MST 최소 스패닝 트리
//가중치 순으로 정렬한다
//간선의 양 끝 정점이 속한 집합을 찾음
//같은 집합이면 두 집합을 합치고
//다른 집합이라면 넘어간다

typedef pair<int, pair<int, int>> Edge;
priority_queue<Edge, vector<Edge>, greater<Edge>> edge;
int an;
int n;

int main() {
	//정점의 개수 받기
	cin >> n;
	Disjoint disjoint(n);
	
	//간선 입력받기


	while (!edge.empty()) {
		Edge e = edge.top();
		edge.pop();
		//두 집합이 다르면
		if (disjoint.find(e.second.first) != disjoint.find(e.second.second)) {
			disjoint.sum(e.second.first, e.second.second);
			//거리 추가
			an += e.first;
		}
	}
	return 0;
}