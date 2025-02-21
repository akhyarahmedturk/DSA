#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
    public:
      string str;
      map<char,bool> mp={{'T',true},{'F',false}};
      vector<vector<vector<int>>> dp;
      int solve(int i,int j,bool res){
          if(dp[i][j][res]!=-1) return dp[i][j][res]; 
          if(i==j){
              return dp[i][j][res]=(mp[str[i]]==res) ;
          }
          int ways=0;
          for(int k=i+1;k<j;k+=2){
              if(str[k]=='&' && res) ways+=solve(i,k-1,true)*solve(k+1,j,true);
              else if(str[k]=='|' && !res) ways+=solve(i,k-1,false)*solve(k+1,j,false);
              else{
                  int a_true=solve(i,k-1,true);
                  int b_true=solve(k+1,j,true);
                  int a_false=solve(i,k-1,false);
                  int b_false=solve(k+1,j,false);
                  
                  if(str[k]=='&') ways+=(a_true*b_false)+(a_false*b_true)+(a_false*b_false);  
                  else if(str[k]=='|') ways+=(a_true*b_true)+(a_true*b_false)+(a_false*b_true);
                  else{
                      if(res) ways+=(a_true*b_false)+(a_false*b_true);
                      else    ways+=(a_false*b_false)+(a_true*b_true);
                  } 
              }
          }
          //cout<<" i "<<i<<" j "<<j<<" res "<<res<<" ways "<<ways<<endl; //T|T&F^T
          return dp[i][j][res]=ways;
      }
      int countWays(string s) {
          str=s;
          int size=s.length();
          dp.resize(size,vector<vector<int>>(size,vector<int>(2,-1)));
          return solve(0,size-1,true);
      }
  };



int main(){
    
    return 0;
}