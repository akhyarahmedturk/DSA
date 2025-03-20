#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

string res;
int k;
void solve(int n, int idx,string curr) {
    if(idx==k && n==1){
        sort(curr.begin(), curr.end());
        if(curr < res) res = curr;
        return;
    }
    for(int i = 2; i <= 9; i++) {
        if(n % i == 0) {
            curr[idx] = i+'0';
            solve(n/i, idx+1, curr);
        }
    }
    return;
}

int main(){
    int n;
    cin >> n >> k;
    res.resize(k,'9');
    string temp=res,curr=res;
    solve(n, 0, curr);
    if(res==temp) cout << -1;
    else cout << res;
    return 0;
}