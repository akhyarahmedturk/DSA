#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        if(n%2==0 && k%2==1) cout<<"NO\n";
        else if(n%2==1 && k%2==0) cout<<"NO\n";
        else if((2*k*k)/2 <= n) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}