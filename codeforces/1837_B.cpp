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
        int n;
        cin>>n;
        // unordered_set<int> st;
        int diff=1,res=1;
        char prv,curr;
        cin>>prv;
        for(int i=1;i<n;i++){
            cin>>curr;
            if(curr!=prv){
                res=max(res,diff+1);
                diff=1;
            }
            else diff++;
            prv=curr;
        }
        cout<<max(res,diff+1)<<endl;
    }
    return 0;
}