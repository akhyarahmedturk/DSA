#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){// i was so dumb using int instead of long long 
    long long t;
    cin >> t;
    while (t--){
        long long n, m, l, u, v;
        cin >> n >> m >> l;
        vector<pair<long long, long long>> hrld(n), jump(m);
        for (long long i = 0;i < n;i++){
            cin >> u >> v;
            hrld[i] = { u,v - u +2};
        }
        for (long long i = 0;i < m;i++){
            cin >> u >> v;
            jump[i] = { u,v };
        }
        long long curr_power = 1,total_power=1, jump_idx = 0;
        long long res = 0;
        priority_queue<long long> pq;
        for (long long i = 0;i < n;i++){
            while (jump_idx < m && jump[jump_idx].first < hrld[i].first){
                pq.push(jump[jump_idx].second);
                total_power += jump[jump_idx].second;
                jump_idx++;
            }
            if (hrld[i].second > total_power){
                res = -1;
                break;
            }
            while (hrld[i].second>curr_power){
                curr_power += pq.top();
                pq.pop();
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}