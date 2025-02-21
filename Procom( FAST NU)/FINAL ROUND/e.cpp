#include<bits/stdc++.h>
using namespace std;

int main() {
    int t ;
    cin >> t ;
    while( t-- ) {
        int n , r ;
        cin >> n >> r ;
        int count = 0 , happy = 0 ;
        for( int i = 0 ; i < n ; i++ ) {
            int temp ;
            cin >> temp ;
            if( temp % 2 == 0 )
                happy += temp ;
            else {
                happy += temp - 1 ;
                count++ ;
            }
            r -= temp / 2 ;
        }

        if( r >= count ) {
            happy += count ;
        }
        else {
            if( count % 2 == 0 ) {
                r -= count / 2 ;
                happy += r * 2 ;
            }
            else {
                r -= count / 2 ;
                happy++ ;
                r-- ;
                happy += r * 2 ;
            }
        }
        
        cout << happy << endl ;
    }
    return 0 ;
}