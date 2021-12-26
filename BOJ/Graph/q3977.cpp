#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
using namespace std;

int t, n, m;
vector<int> ve[100005];
stack<int> s;
set<int> inDeg[100005];
int id[100005];
int finished[100005];
int scc[100005];
int cnt = 1;
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
    if(ret == id[x]){
        while(!s.empty()){
            int te = s.top();
            s.pop();
            finished[te] = 1;
            scc[te] =number;
            if(x == te)
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
        cnt = 1; number =0;
        for(int i =0; i < 100005; i++){
            inDeg[i].clear();
            ve[i].clear();
        }
        memset(finished, 0, sizeof(finished));
        memset(id, 0, sizeof(id));
        memset(scc, 0, sizeof(scc));
        
        cin >> n >> m;
        for(int i= 0; i < m; i++){
            int a, b; cin >> a >> b;
            ve[a].push_back(b);
        }
        for(int i = 0; i< n; i++){
            if(id[i] == 0)
                dfs(i);
        }
        for(int i =0; i < n; i++){
            for(int j : ve[i]){
                if(scc[i] != scc[j]){
                    inDeg[scc[j]].insert(scc[i]);
                }
            }
        }
        int pos = -1;
        for(int i =0; i < number; i++){
            if(inDeg[i].size() == 0){
                if(pos == -1)
                    pos = i;
                else pos = -2;
            }
        }
        if(pos == -2)
            cout << "Confused\n\n";
        else{
            for(int i =0; i < n; i++){
                if(scc[i] == pos)
                    cout << i << "\n";
            }
            cout << "\n";
        }
    }
    return 0;
}
