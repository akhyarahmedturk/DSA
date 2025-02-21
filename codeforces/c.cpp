#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int res=0;
    while(a>0 && b>0){
        if(a==b) break;
        if(a<b) swap(a,b);
        if(a%2==0) a/=2;
        else if(a%3==0) a=a/3;
        else if(a%5==0) a=a/5;
        else  {
            break;
        }
        res++;
    }
    if(a!=b) cout<<-1;
    else cout<< res;
    return 0;
}