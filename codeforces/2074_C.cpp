#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,check=0;
        cin>>x;
        vector<int> bits;
        long long temp=x,one,i=0,z;
        while(temp){
            if(temp%2) {
                check++;
                one=i;
            }
            else z=i;
            bits.push_back(temp%2);
            temp/=2;
            i++;
        }
        if(check==1 || check==bits.size()) cout<<-1<<endl;
        else{
            long long y=pow(2,z)+pow(2,one);
            long long c=x^y;
            cout<<min(y,c)<<endl;
        }
    }
    return 0;
}