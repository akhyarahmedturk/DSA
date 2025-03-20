#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long double a,b;
        cin>>a>>b;
        if(b>a) {
            cout<<1<<endl;
            continue;
        }
        long double ans,start=0,res,end;
        if(b>1) ans=ceil(log2(a) / log2(b));
        else{
            ans=ceil(log2(a) / log2(2*1.0));
            start=2-b;
        }
        if(a/pow(b+start,ans)>=1) ans++;
        res=ans+start;
        end=res-1;
        for(int i=start+1;i<=end;i++){
            ans=min(ans,ceil(log2(a) / log2(b+i)));
            if(a/pow(b+i,ans)>=1) ans++;
            res=min(res,i+ans);
        }
        cout<<res<<endl;
    }
    return 0;
}