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
        int n,m;
        cin>>n>>m;
        long long abs_min=LLONG_MAX,sum=0,neg_nums=0,temp;
        for(int i=0;i<n*m;i++){
            cin>>temp;
            sum+=abs(temp);
            if(temp<0) neg_nums++;
            abs_min=min(abs_min,abs(temp));
        }
        if(neg_nums%2==0) cout<<sum<<endl;
        else cout<<sum-abs_min*2<<endl;
    }
    return 0;
}