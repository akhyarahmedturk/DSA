#include<bits/stdc++.h>
using namespace std;

void fact( int n , set<long long>& hash ) {
    long long val = 1 ;
    for( int i = 1 ; i <= 16 ; i++ ) {
        val *= i ;
        hash.insert( val ) ;
    }
}

long long ans = INT_MAX ;
unordered_map< long long , long long > sums ;

void solve( long long n , vector<long long>& hash , long long i ) {
    // cout << n << endl ;
    if( sums.count( n ) ) {
        sums[n] = min( sums[n] , i ) ;
        return ;
    }
    else
        sums[n] = i ;

    for( int j = hash.size() - 1 ; j >= 0 ; j-- ) {
        if( hash[j] != -1 && n - hash[j] >= 0 ) {
            long long temp = hash[j] ;
            hash[j] = -1 ;
            solve( n + temp , hash , i + 1 ) ;
            hash[j] = temp ;
        }
    }
}

int main() {
    int t ;
    cin >> t ;
    set<long long> hash ;
    fact( 15, hash ) ;
    for( long long i = 1 ; i <= 45 ; i++ )
        hash.insert( 1LL << i ) ;
    
    vector<long long> vals ;
    for( long long val : hash )
        vals.push_back( val ) ;
    
    solve( 0 , vals , 0 ) ;
    // for( auto& itr : hash )
    //     cout << itr << endl ;
    
    while( t-- ) {
        long long x ;
        cin >> x ;
        // cout << x << endl ;
        if( sums.count( x ) )
            cout << sums[x] << endl ;
        else
            cout << -1 << endl ;
        ans = INT_MAX ;
    }
    return 0 ;
}