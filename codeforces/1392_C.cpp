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
        long long n, res = 0, prv = 0;
        cin >> n;
        long long i, temp;
        for (i = 0;i < n;i++){
            cin >> temp;
            if (temp >= prv) prv = temp;
            else{
                res += prv - temp;
                prv = temp;
            }
        }
        cout << res << endl;
    }
    return 0;
}