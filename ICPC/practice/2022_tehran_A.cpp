#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int n,res,temp;
    cin>>n;
    cin>>res;
    n--;
    while(n--){
        cin>>temp;
        if(res+temp>=0 && res+temp<1000000) res+=temp;
    }
    cout<<res;
    return 0;
}