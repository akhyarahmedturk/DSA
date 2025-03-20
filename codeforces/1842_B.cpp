#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

void bit_mask(int n,vector<bool> &x_bits,vector<bool> &res_bits){
    int i=0;
    long long temp;
    vector<bool> temp_bits(30,false);
    for(;i<n;i++){
        cin>>temp;
        bool check = false;
        for(int j=0;temp>0;j++){
            if(temp%2){
                if(!x_bits[j]){
                    check = true;
                    i++;
                    break;
                }
                temp_bits[j]=true;
            }
            temp/=2;
        }
        if(check) break;
        for(int j=0;j<30;j++) {
            if(temp_bits[j]) res_bits[j] = true;
        }
    }
    while(i<n) {
        cin>>temp;
        i++;
    } 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,x;
        cin>>n>>x;
        vector<bool> x_bits(30,false);
        vector<bool> res_bits(30,false);
        for(int i=0;x;i++){
            if(x%2==1) x_bits[i] = true;
            x/=2;
        }
        bit_mask(n,x_bits,res_bits);
        bit_mask(n,x_bits,res_bits);
        bit_mask(n,x_bits,res_bits);
        bool check=true;
        for(int i=0;i<30;i++){
            if(res_bits[i]!=x_bits[i]) check = false;
        }
        if(check) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}