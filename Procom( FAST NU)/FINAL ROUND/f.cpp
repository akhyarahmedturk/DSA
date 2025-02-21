#include<bits/stdc++.h>
using namespace std;

bool check( vector<long long>& arr, long long skill ) {
    int n = arr.size() ;
    for( int i = 0 ; i < n ; i++ ) {
        if( arr[i] >= skill )
            return false ;
        
        skill += arr[i] ;
    }
    return true ;
}

int main() {
    int n ;
    cin >> n ;
    vector<long long> bugs( n ) ;
    for( int i = 0 ; i < n ; i++ )
        cin >> bugs[i] ;
    
    sort( bugs.begin() , bugs.end() ) ;
    long long l = 1LL , r = bugs[n - 1] + 10 , ans = 1LL ;
    while( l <= r ) {
        long long mid = l + ( r - l ) / 2 ;
        if( check( bugs, mid ) ) {
            ans = mid ;
            r = mid - 1 ;
            // cout << ans << endl ;
        }
        else
            l = mid + 1 ;
    }

    cout << ans << '\n' ;
    return 0 ;
}