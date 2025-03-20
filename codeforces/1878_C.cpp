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
        long long n,k,x;
        cin>>n>>k>>x;
        if(((k+1)*k)/2 <= x && ((2*(n-k+1)+k-1)*k)/2 >= x) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}