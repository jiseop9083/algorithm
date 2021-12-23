//백준 17412번 도시 왕복하기1
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;


class Flow {
public:
	struct Edge {
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
		n(0), source(1), sink(2), graph(), visit() {}
	Flow(const Flow& f) :
		n(f.n), source(f.source), sink(f.sink), graph(f.graph), visit(f.visit) {}
	Flow(int n) :
		n(n), source(1), sink(2), graph(n), visit(n) {}


	void add(int from, int to) {
		Edge* e = new Edge(from, to, 1);
		Edge* e_reverse = new Edge(to, from, 0);
		graph[from].push_back(e);
		graph[to].push_back(e_reverse);
		e->reverse = e_reverse;
		e_reverse->reverse = e;
	}

	//현재 위치, 한번에 채울 수 있는 최대량
	int dfs(int now, int maxflow) {
		if (now == sink)
			return maxflow;
		if (visit[now])
			return 0;
		visit[now] = true;

		for (auto e : graph[now]) {
			if (e->capa > e->flow) {
				int flow = dfs(e->to, min(maxflow, e->capa - e->flow));
				if (flow > 0) {
					e->flow += flow;
					e->reverse->flow -= flow;
					return flow;
				}
			}
		}
		//아무데도 못감
		return 0;
	}

	int answer() {
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
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, p;
	cin >> n >> p;
	Flow flow(n+5);
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		flow.add(a, b);
	}
	cout << flow.answer();
	return 0;
}