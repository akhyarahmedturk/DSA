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
    cin >> t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int temp,prv=0;
        bool check=true;
        for(int i=0;i<n;i++) {
            cin>>temp;
            if(temp<prv) check=false;
            prv=temp;
        }
        if(k>1 || check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}