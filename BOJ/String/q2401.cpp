#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int dp[100005]; // answer
int pi[505][100005];
string pattern[505];
int subSize[505];
int N;

void getPi(string arr, int index){
    int len = arr.size();
    int start = 1;
    int matched = 0;
    while(start + matched < len){
        if(arr[start + matched] == arr[matched]){
            pi[index][start + matched] = 1 + matched;
            matched++;
        } else{
            if(matched == 0){
                start++;
            } else{
                start += (matched - pi[index][matched - 1]);
                matched = pi[index][matched - 1];
            }
        }
    }
}

void getMatchPos(string arr){
	int len = arr.size();
    int start[505];
	int matched[505];
    memset(start, 0, sizeof(start));
    memset(matched, 0, sizeof(matched));

    for(int i =0; i < N; i++){
        getPi(pattern[i], i);
    }
    for(int j = 0; j < len; j++){
        if(j>0) dp[j] = dp[j-1]; 
        for(int i = 0; i < N; i++){
            while (matched[i] > 0 && arr[j] != pattern[i][matched[i]]) 
                matched[i] = pi[i][matched[i] - 1];
            if (arr[j] == pattern[i][matched[i]]) {
                if (matched[i] == subSize[i] - 1) { 
                    int temp = j - subSize[i] >= 0 ? dp[j - subSize[i]] : 0; 
                    dp[j] = max(dp[j], temp + subSize[i]);
                    matched[i] = pi[i][matched[i]];
                }
                else matched[i]++;
            }
        }
    }
}

bool com(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }else{  
        return a.first < b.first;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string arr;
    int n;
    cin >> arr;
    cin >> N;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < N; i++){
        cin >> pattern[i];
        subSize[i] = pattern[i].size();
    }
    getMatchPos(arr);

    // for(int i =0; i < arr.size(); i++){
    //     cout << dp[i] << "\n";
    // }
    cout << dp[arr.size()-1];

    return 0;
}