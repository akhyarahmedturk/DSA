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
    while (t--){//not solved yet
        long long n, a, b, c, cost = 0, i = 0;
        cin >> n >> a >> b >> c;
        cost = c * 2LL;
        long long zero, one;
        string str;
        cin >> str;
        bool first = true;
        while (i < n){
            zero = 0;
            one = 0;
            while (i < n && str[i] == '0'){
                i++;
                zero++;
            }
            if (first){
                if (a * (zero + 1) + b * (zero - 1) < a * (zero + 1) + b * (zero - 1)) cost +=
            }
        }
    }
    return 0;
}