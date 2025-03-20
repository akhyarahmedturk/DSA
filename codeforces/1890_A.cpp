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
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            freq[temp]++;
        }
        if(freq.size()>=3) cout<<"No\n";
        else if(n<=3 || freq.size()==1)cout<<"Yes\n";
        else{
            int a=0,b=0;
            for(auto it=freq.begin();it!=freq.end();it++){
                swap(a,b);
                b=it->second;
            }
            if((a==b && n%2==0) || (n%2==1 && abs(a-b)==1)) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}