#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int t ;
    cin >> t ;
    while( t-- ) {
        int n , k ;
        cin >> n >> k ;
        vector<int> ans( k + 1 , 0 ) ;
        for( int i = 0 ; i < k ; i++ ) {
            int b , c ;
            cin >> b >> c ;
            ans[b] += c ;
        }
            
        sort( ans.begin() , ans.end() , greater<int>() ) ;
        int sum = 0 ;
        for( int i = 0 ; i < n && i < k ; i++ ) {
            // cout << "Ans = " << ans[i] << endl ;
            if( !ans[i] )
                break ;
            sum += ans[i] ;
        }
        
        cout << sum << '\n' ;
    }
    return 0;
}