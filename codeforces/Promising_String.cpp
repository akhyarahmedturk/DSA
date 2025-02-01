#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct cell{
    int plus,minus,con;
    cell(int p=0,int m=0,int c=0){
        plus=p;
        minus=m;
        con=c;
    }
};
int main(){
    int T,size,temp,cons,p,m,res;
    string s;
    cin>>T;
    while(T--){
        cin>>size;
        cin>>s;
        vector<cell> vec(size+1,{0,0,0});
        res=temp=0;
        if(s[0]=='+') vec[1].plus=1;
        else {
            vec[1].minus=1;
            temp++;
        }
        for(int i=2;i<=s.length();i++){
            vec[i]=vec[i-1];
            if(s[i-1]=='+'){
                temp=0;
                vec[i].plus++;
            }
            else{
                temp++;
                vec[i].minus++;
            }
            if(temp!=0 && temp%2==0) vec[i].con++;
            //cout<<" + "<<vec[i].plus<<" - "<<vec[i].minus<<" c "<<vec[i].con<<endl;
        }
        for(int i=2;i<=s.length();i++){
            for(int j=i;j<=s.length();j++){
                int diff=(vec[j].minus-vec[j-i].minus)-(vec[j].plus-vec[j-i].plus);
                if(diff==0) res++;
                else if(diff>0){
                    if(diff%3==0 && diff/3<=(vec[j].con-vec[j-i+1].con)) res++;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}