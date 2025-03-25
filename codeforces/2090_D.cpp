// #include<iostream>
// #include<vector>
// #include<stack>
// #include<queue>
// #include<unordered_map>
// #include<unordered_set>
// #include<algorithm>
// #include<cmath>
// #include<cstring>
// #include<iomanip>
// using namespace std;
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
vector<int> sieve(int n){
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++){
        if (is_prime[i]){
            for (int j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++){
        if (is_prime[i]){
            primes.push_back(i);
        }
    }
    return primes;
}


void solve(vector<int>& primes){
    int n, pre_sum = 0, p = 0, i = 1,t=0,lim;
    cin >> n;
    lim=n*(n+1)/2
    p = n / 3 - 1;
    vector<bool> visited(n + 1, false);
    vector<int> res;
    for (;t <= p;i++){
        int curr = -1;
        for (int j = 0;j < primes.size() && curr == -1 && primes[j]<lim;j++){
            int start = max(1LL, i * (primes[j]-1)-pre_sum+1LL), end = min(n,i * (primes[j]) -pre_sum);
            for (int k = start;k <= end ;k++){
                if (!visited[k]){
                    visited[k] = true;
                    curr = k;
                    break;
                }
            }
        }
        if(curr!=-1){
            res.push_back(curr);
            pre_sum += curr;
            t++;
        }
        else{
            forr(i,n,1){
                if(!visited[i]){
                    res.push_back(i);
                    pre_sum += i;
                    visited[i]=true;
                    break;
                }
            }
        }
    }
    int j = 1;
    while (res.size()*1LL!=n){
        while (visited[j]) j++;
        res.push_back(j);
        j++;
    }
    for (int i = 0;i < n;i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

int32_t main(){
    int t = 1;
    cin >> t;
    vector<int> primes = sieve(10000);
    while (t--){
        solve(primes);
    }
    return 0;
}