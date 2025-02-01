#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    double length,n,x,s;
    cin>>n>>length;
    pair<int,double> res;
    cin>>x>>s;
    res={1,abs(length-x)/s};
    for(int i=2;i<=n;i++){
        cin>>x>>s;
        if(abs(length-x)/s<res.second) res={i,abs(length-x)/s};
    }
    cout<<res.first;
    return 0;
}