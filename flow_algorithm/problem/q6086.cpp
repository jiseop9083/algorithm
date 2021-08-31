//Ford Fulkerson Algorithm
//시작점에서 DFS를 여러번 쓴다
//한 번 DFS를 쓸 때마다 최대로 흘린다
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

class Flow {
public:
	class Edge {
	public:
		int from, to, capa, flow;
		Edge* reverse;
		Edge() :
			from(0), to(0), capa(0), flow(0), reverse(nullptr) {}
		Edge(const Edge& edge) :
			from(edge.from), to(edge.to), capa(edge.capa), flow(edge.flow), reverse(edge.reverse) {}
		Edge(int from, int to, int capa) :
			from(from), to(to), capa(capa), flow(0), reverse(nullptr) {}

	};

	int n, source, sink;
	vector<vector<Edge*>> graph;
	vector<bool> visit;

	Flow() :
		n(0), source(0), sink(0), graph(), visit() {}
	Flow(const Flow& f) :
		n(f.n), source(f.source), sink(f.sink), graph(f.graph), visit(f.visit) {}
	Flow(int n, int source, int sink) :
		n(n), source(source), sink(sink), graph(n), visit(n) {}

	void add_edge(int from, int to, int capa) {
		Edge* e = new Edge(from, to, capa);
		Edge* e_reverse = new Edge(to, from, 0);
		graph[from].push_back(e);
		graph[to].push_back(e_reverse);
		e->reverse = e_reverse;
		e_reverse->reverse = e;
	}

	int dfs(int now, int maxflow) {
		if (now == sink) {
			return maxflow;
		}
		if (visit[now]) {
			return 0;
		}
		visit[now] = true;

		for (auto e : graph[now]) {
			//용량이 남아있다면
			if (e->capa - e->flow > 0) {
				int flow = dfs(e->to, min(maxflow, e->capa - e->flow));

				if (flow > 0) {
					e->flow += flow;
					e->reverse->flow -= flow;
					return flow;
				}
			}
		}

		return 0;
	}

	int maximum_flow() {
		int ret = 0;
		while (1) {
			int flow = dfs(source, INF);
			fill(visit.begin(), visit.end(), false);
			if (flow == 0) {
				break;
			}
			ret += flow;
		}
		return ret;
	}
};

int n;
char start, en;
int capa;
int number[200];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 26; i++) {
		number['A' + i] = i;
		number['a' + i] = i + 26;
	}
	Flow flow(100, 0, 25);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> en >> capa;
		flow.add_edge(number[start], number[en], capa);
		flow.add_edge(number[en], number[start], capa);

	}
	cout << flow.maximum_flow();
}