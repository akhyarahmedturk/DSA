#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;


int main(){
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q;
    cin >> Q;

    string str, res;
    stack<string> stk;
    stack< pair<int, int>> last;

    for (int i = 0; i < Q; i++){
        int x, k;
        cin >> x;
        if (x == 1){
            cin >> str;
            res += str;
            last.push({ x , str.length() });
        }
        else if (x == 2){
            cin >> k;
            int n = res.length();
            stk.push(res.substr(n - k, n));
            res = res.substr(0, n - k);
            last.push({ 2 , 0 });
        }
        else if (x == 3){
            cin >> k;
            cout << res[k - 1] << endl;
        }
        else if (x == 4){
            pair<int, int> a = last.top();
            last.pop();
            if (a.first == 1){
                res = res.substr(0, res.length() - a.second);
            }
            else if (a.first == 2){
                str = stk.top();
                stk.pop();
                res += str;
            }
        }
        // cout << "REs = " << res << endl ;
        string b = "REHAN";
        string c = b.substr(0, 3);
    }
    return 0;
}