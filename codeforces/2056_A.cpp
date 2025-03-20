#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        int x,y,a,b;
        cin>>x>>y;
        n--;
        long long peri=m*4;
        while(n--){
            cin>>a>>b;
            peri+=4*m-2*(m-a)-2*(m-b);
            x+=a;
            y+=b;
        }
        cout<<peri<<endl;
    }
    return 0;
}