#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        double n,k,p,sum=0,res=0;
        cin>>n>>k>>p;
        if(k==0) {
            cout<<0<<endl;
            continue;
        }
        if(k>0) res=ceil(k/p);
        else res=ceil(-k/p);
        if(res<=n) cout<<res<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}