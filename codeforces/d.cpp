#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int w1,w2,h1,h2;
    cin>>w1>>h1>>w2>>h2;
    int res=0;
    res+=(h1+h2+w1)*2+4;
    cout<<res;
    return 0;
}