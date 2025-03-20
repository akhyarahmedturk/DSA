#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int t=1;
    cin>>t;
    while(t--){
        long long n,d,prv,res=0,curr,a_s,a_e;
        cin>>n>>d;
        cin>>curr;
        a_s=curr-d;
        a_e=curr+d;
        for(int i=1;i<n;i++){
            cin>>curr;
            if(curr<a_s-d || curr>a_e+d){
                res++;
                a_s=curr-d;
                a_e=curr+d;
            }
            else{
                a_s=max(a_s,curr-d);
                a_e=min(a_e,curr+d);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}