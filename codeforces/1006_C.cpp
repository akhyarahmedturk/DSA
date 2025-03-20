#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n, x;
        cin>>n>>x;
        vector<bool> st(32,false),st1(32,false);
        int temp=x;
        for(int i=0;temp;i++){
            if(temp%2==1) {
                st[i]=st1[i]=true;
            }
            temp/=2;
        }
        int i=0;
        for(;i<n;i++){
            int temp=i;
            bool check=false;
            for(int j=0;temp;j++){
                if(temp%2==1) {
                    if(!st[j]) {
                        check=true;
                        break;
                    }
                }
                temp/=2;
            }
            if(check) break;
            temp=i;
            for(int j=0;temp;j++){
                if(temp%2==1) st1[j]=false;
                temp/=2;
            }
        }
        if(i<n){
            cout<<x<<" ";
            n--;
            for(int j=0;j<i;j++,n--) cout<<j<<" ";
            while(n--) cout<<0<<" ";
        }
        else{
            bool check=false;
            for(auto it:st1){
                if(it) check=true;
            }
            if(check){
                // cout<<" checking ";
                for(int j=0;j<i-1;j++) cout<<j<<" ";
                cout<<x<<" ";
            }
            else{
                for(int j=0;j<i;j++) cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}