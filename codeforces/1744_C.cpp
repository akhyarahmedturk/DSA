#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, start = 0;
        char ch;
        cin >> n >> ch;
        string str;
        cin >> str;
        if (n == 1){
            cout << 0 << endl;
            continue;
        }
        for (int i = 0;i < n;i++){
            str += str[i];
            if (str[i] == 'g') break;
        }
        while (str[start] != ch) start++;
        int count = 0, res = 0;
        for (int i = start;i < str.length();i++){
            // cout<<" count "<<count<<" i "<<i<<endl;
            if (str[i] == 'g'){
                res = max(res, count);
                count = 0;
            }
            else if (str[i] != ch && count == 0) count = 0;
            else count++;
        }
        cout << res << endl;
    }
    return 0;
}