#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int H,W,num,Q,x1,x2,y1,y2;
    cin>>H>>W;
    vector<vector<vector<int>>> grid(H,vector<vector<int>>(W,vector<int>(8,0)));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int num;
            cin>>num;
            for(int k=0;num>0;k++){
                if(num%2) grid[i][j][k]=1;
                num/=2;
            }
        }
    }

    return 0;
}