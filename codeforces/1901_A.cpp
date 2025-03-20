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
        int n,x;
        cin>>n>>x;
        int max_diff=0;
        int prv=0,temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            max_diff=max(max_diff,temp-prv);
            prv=temp;
        }
        cout<<max(max_diff,2*(x-prv))<<endl;
    }
    return 0;
}