#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<int> bits(32,0);
        for(int i=0;i<m;i++){
            int temp;
            cin>>temp;
            for(int j=0;temp;j++){
                bits[j]+=(temp%2);
                temp/=2;
            }
        }
        int XOR1=0;
        for(int i=0;i<32;i++){
            if(bits[i]%2) XOR1+=pow(2,i);
        }
        int parity=1;
        if(m%2==0) parity=2;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            for(int j=0;temp;j++){
                if(temp%2) bits[j]=parity;
                temp/=2;
            }
        }
        int XOR2=0;
        for(int i=0;i<32;i++){
            if(bits[i]%2) XOR2+=pow(2,i);
        }
        if(m%2==0) cout<<XOR2<<" "<<XOR1<<endl;
        else cout<<XOR1<<" "<<XOR2<<endl;
    }
    return 0;
}