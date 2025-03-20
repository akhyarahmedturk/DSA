#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n, up = 0, down = 0;
        cin >> n;
        for (int i = 0;i < n;i++){
            char ch;
            cin >> ch;
            if (ch == '_') down++;
            else up++;
        }
        // cout<<"up "<<up<<" down "<<down<<endl;
        if (up < 2 || down == 0) cout << 0 << endl;
        else if (up % 2) cout << (up / 2) * down * (up / 2 + 1) << endl;
        else cout << (up / 2) * down * (up / 2) << endl;
    }
    return 0;
}