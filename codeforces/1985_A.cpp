#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin>>n>>k;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            int r=-1,s=0,a,b;
            cin>>a;
            b=a;
            while(b){
                if(b%2==0) { if(r==-1) r=s; }
                s++;
                b/=2;
            }
            if(r==-1) r=s;
            b=pow(2,r);
            pq.push({b,a});
        }
        while(k>=pq.top().first){
            // cout<<" p "<<pq.top().first<<" sec "<<pq.top().second<<endl;
            int a=pq.top().first+pq.top().second;
            k-=pq.top().first;
            pq.pop();
            int b=a,s=0,r=-1;
            while(b){
                if(b%2==0) { if(r==-1) r=s; }
                s++;
                b/=2;
            }
            if(r==-1) r=s;
            b=pow(2,r);
            pq.push({b,a});
        }
        int res=0;
        while(!pq.empty()){
            int a=0;
            a=pq.top().second;
            pq.pop();
            while(a){
                if(a&1) res++;
                a/=2;
            }
        }
        cout<<res<<endl;
    }
}