#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
using namespace std;

int t;
int n, m;
int scc[20005];
int cnt = 1;
vector<int> ve[20005];
set<int> inDeg[20005];
set<int> outDeg[20005];
stack<int> s;
int id[20005];
int finished[20005];
int number = 0;

int dfs(int x){
    id[x] = cnt++;
    s.push(x);
    int ret = id[x];
    for(int i : ve[x]){
        if(id[i] == 0)
            ret = min(ret, dfs(i));
        else if(finished[i] == 0)
            ret = min(ret, id[i]);
    }
    if(id[x] == ret){
        while(!s.empty()){
            int te = s.top();
            s.pop();
            finished[te] = 1;
            scc[te] = number;
            if(te == x)
                break;
        }
        number++;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test = 0; test < t; test++){
        memset(id, 0, sizeof(id));
        memset(finished, 0, sizeof(finished));
        memset(scc, 0, sizeof(scc));
        number = 0;
        cnt = 1;
        for(int i = 0; i < 20005; i++){
            ve[i].clear();
            inDeg[i].clear();
            outDeg[i].clear();
        }
        while(!s.empty())
            s.pop();
            
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            ve[a].push_back(b);
        }
        for(int i = 1; i <= n; i++){
            if(id[i] == 0)
                dfs(i);
        }
        for(int i = 1; i <= n; i++){
            for(int j : ve[i]){
                if(scc[i] != scc[j]){
                    outDeg[scc[i]].insert(scc[j]);
                    inDeg[scc[j]].insert(scc[i]);
                }
                    
            }
        }
        int mi = 0;
        int ma = 0;
        for(int i = 0; i < number; i++){
            if(outDeg[i].size() == 0){
                mi++;
            }
            if(inDeg[i].size() == 0)
                ma++;
        }
        if(number == 1)
            cout << "0\n";
        else cout << max(mi, ma) << "\n";
    }
    return 0;
}
