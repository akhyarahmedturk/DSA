#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<math.h>
using namespace std;

void compute_xor(vector<vector<vector<int> > > &grid,int H,int W){
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            for(int k=0;k<9;k++){
                grid[i][j][k]=(grid[i-1][j][k]+grid[i][j-1][k]+grid[i-1][j-1][k]+grid[i][j][k])%2;
            }
        }
    }
}

int main(){
    int H,W,num,Q,x1,x2,y1,y2;
    cin>>H>>W;
    vector<vector<vector<int>>> grid(H+1,vector<vector<int>>(W+1,vector<int>(9,0)));
    // first row and col are dummy just for ease in calculation only
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            int num;
            cin>>num;
            for(int k=0;num>0;k++){
                if(num%2) grid[i][j][k]=1;
                num/=2;
            }
        }
    }
    compute_xor(grid,H,W);
    cin>>Q;
    int q=1;
    while(q<=Q){
        cin>>x1>>y1>>x2>>y2;
        int res=0;
        vector<int> temp(9,0);
        for(int k=0;k<9;k++){
            if((grid[y2+1][x2+1][k]+grid[y1-1+1][x2+1][k]+grid[y2+1][x1-1+1][k]+grid[y1-1+1][x1-1+1][k])%2){
                res+=pow(2,k);
            }
        }
        cout<<"Query #"<<q<<": "<<res<<endl;
        q++;
    }
    return 0;
}