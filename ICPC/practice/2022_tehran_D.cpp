#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<math.h>
using namespace std;
double pi=3.14159265;
double solve(int i, vector<pair<double,double>> &arr,vector<double> &dp){
    double res=0;
    int j=i-1;
    dp[i]=(pi*arr[i].second*arr[i].second)/4.0;
    while(j>0){
        if((arr[i].first-arr[i].second>arr[j].first-arr[j].second) && 
           (arr[i].first-arr[i].second<arr[j].first)){
            double dx=arr[i].first-arr[j].first,dy=arr[i].second;
            double height_of_j=sqrt(dy*dy-dx*dx);
            dp[i]+= (dp[j]- (atan(height_of_j/dx)*dy*dy)/2.0 + (dx*height_of_j)/2);
            break;
        }
        else if(arr[i].first-arr[i].second>=arr[j].first){
            break;
        }
        j--;
    }
    return dp[i];
}

int main(){
    int size;
    cin>>size;
    vector<pair<double,double>> arr(size+1,{0,0});
    vector<double> dp(size+1);
    for(int i=1;i<=size;i++){
        cin>>arr[i].first>>arr[i].second;
        cout<<solve(i,arr,dp)<<endl;
    }
    return 0;
}