#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

int res;
vector<long long> mp;
void fact() {
    long long val = 6 ,k=4;
    while(val<= 1e13) {
        mp.push_back(val) ;
        val *= k ;
        k++;
    }
}

void solve(int idx,long long num,int count) {
    if(idx==-1) {
        int temp=0;
        while(num){
            temp += num%2 ;
            num /= 2 ;
        } 
        res=min(res,temp+count);
        return;
    }
    solve(idx-1,num,count);
    if(mp[idx] > num) return;
    num-=mp[idx] ;
    solve(idx-1,num,count+1);   
    num+=mp[idx] ;
}

int main() {
    int t ;
    cin >> t ;
    fact() ;
    while( t-- ) {
        long long x ;
        cin >> x ;
        long long temp=x;
        res=100;
        solve(mp.size()-1,temp,0);
        cout<<res<<endl;
    }
    return 0 ;
}