#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int t, n, m;
int scc[100005];
vector<int> ve[100005];
vector<int> chk[100005];
stack<int> s;
int id[100005];
int finished[100005];
int cnt =1;
int number = 0;
int com[100005];

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
        vector<int> temp;
        while(!s.empty()){
            int t = s.top();
            s.pop();
            finished[t] = 1;
            temp.push_back(t);
            if(x == t)
                break;
        }
        for(int i : temp){
            scc[i] = number;
        }
        number++;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test = 0; test < t; test++){
        memset(id, 0, sizeof(id));
        memset(finished, 0, sizeof(finished));
        memset(scc, 0, sizeof(scc));
        memset(com, 0, sizeof(com));
        for(int i =0; i< 100005; i++){
            ve[i].clear();
            chk[i].clear();
        }
        while(!s.empty())
            s.pop();
        cnt = 1;
        number = 0;
        cin >> n >> m;
        for(int i =0; i < m; i++){
            int a, b;
            cin >> a >> b;
            ve[a].push_back(b);
            chk[b].push_back(a);
        }
        for(int i = 1; i <= n; i++){
            if(id[i] == 0){
                dfs(i);
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j : chk[i]){
                if(com[scc[i]] == 0 && scc[i] != scc[j]){
                    com[scc[i]] = 1;
                    number--;
                    break;
                }

            }
        }
        cout << number << "\n";
    }
    return 0;
}
