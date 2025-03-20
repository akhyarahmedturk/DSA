#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        long long n, m, ans = 0LL;
        cin >> n >> m;
        if (n <= m) ans = 1LL;
        else{
            if (n % 2 == 1){
                n -= m;
                ans++;
            }
            ans += ceil((n * 1.0) / (m - 1));
        }
        cout << ans << endl;
    }
    return 0;
}