#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


vector<int> getPi(string pattern){
    int len = pattern.size();
	vector<int> ret(len, 0);
	int start = 1;
	int matched = 0;
    while(start + matched < len){
        if(pattern[start + matched] == pattern[matched]){
            ret[start + matched] = matched + 1;
            matched++;
        } else{
            if(matched == 0){
                start++;
            } else{
                start += (matched - ret[matched - 1]);
                matched = ret[matched - 1];
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string arr;
    cin >> n >> arr;
    vector<int> pi = getPi(arr);
    cout << n - pi[n-1];
    return 0;
}