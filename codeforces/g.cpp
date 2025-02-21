#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int sum=0,n,Max=0,temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        sum+=temp;
        Max=max(Max,temp);
    }
    if(sum%2==1) cout<<"NO";
    else if(sum<Max*2) cout<<"NO";
    else cout<<"YES";
    return 0;
}