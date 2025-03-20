#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    // struct comp{
    //     bool operator()(vector<long long>&a,vector<long long> &b){
    //         if(a[0]==b[0]) return a[1]>b[1];
    //         else return a[0]<b[0];
    //     } 
    // };
    int t;
    cin>>t;
    while(t--){
        long long n,k,res=0,total,idx,cost,i;
        cin>>n>>k;
        total=n;
        vector<vector<long long>> vec(n,vector<long long>(2));
        for(int i=0;i<n;i++) cin>>vec[i][1];    
        for(int i=0;i<n;i++) cin>>vec[i][0];
        sort(vec.begin(),vec.end());
        queue<pair<int,int>> q;
        if(vec[0][0]<k)  q.push({0,k});
        i=1;
        while(!q.empty() && total){
            auto [idx,cost] =q.front();
            // cout<<" idx "<<idx<<" c "<<cost<<" to "<<total<<endl;
            q.pop();
            res+=cost;
            total--;
            if(vec[idx][0]>=k) continue;
            for(int j=0;j<vec[idx][1] && i+j<n;j++){
                q.push({i+j,vec[idx][0]});
            }
            i+=vec[idx][1];
        }
        if(total) res+=(total*k);
        cout<<res<<endl;
    }
    return 0;
}