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
        long long n,temp,break_point;
        cin>>n;
        int bits=0;
        n--;
        temp=n;
        while(temp){
            temp/=2;
            bits++;
        }
        break_point=pow(2,bits-1);
        while(n>=break_point){
            cout<<n<<" ";
            n--;
        }
        cout<<0<<" ";
        while(n){
            cout<<n<<" ";
            n--;
        }
        cout<<endl;
    }
    return 0;
}