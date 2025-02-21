#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<limits>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
using namespace std ;

int main() {
    int n ;
    cin >> n ;
    int a = sqrt(n) ;
    int ans = 3 * a ;
    n -= a * a ;
    if( n == 0 )
        ans += a ;
    else if(n<=a) ans+=a+2;
    else {
        ans+=a+4;
    }
    cout << ans << '\n' ;
    return 0 ;
}