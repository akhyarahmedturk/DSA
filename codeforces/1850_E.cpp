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
        long long n,c,a,b=0LL;
        cin>>n>>c;
        a=1LL;
        for(long long i=0;i<n;i++){
            long long temp;
            cin>>temp;
            b+=temp;
            c-=(temp*temp);
        }
        b/=n;
        c/=(4LL*n);
        long long ans= (-1LL*b + sqrt(b*b + (4LL*a*c) ) )/(2LL*a);
        cout<<ans<<endl;
    }
    return 0;
}