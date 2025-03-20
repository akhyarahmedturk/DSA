#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<pair<int,int>> moves({{1,1},{1,-1},{-1,1},{-1,-1}});
    while(t--){
        int a,b,kx,ky,qx,qy;
        cin>>a>>b>>kx>>ky>>qx>>qy;
        set<pair<int,int>> visited;
        for(auto d:moves){
            int nx=kx+d.first*a, ny=ky+d.second*b;
            if((abs(nx-qx)==a && abs(ny-qy)==b) || (abs(nx-qx)==b && abs(ny-qy)==a)) visited.insert({nx,ny});
            nx=kx+d.first*b, ny=ky+d.second*a;
            if((abs(nx-qx)==a && abs(ny-qy)==b) || (abs(nx-qx)==b && abs(ny-qy)==a)) visited.insert({nx,ny});
        }
        cout<<visited.size()<<endl;
    }
    return 0;
}