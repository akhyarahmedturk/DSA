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
        string str;
        cin >> str;
        int n = str.length() ;
        unordered_set<int> hash;
        int k = 0 , i ;
        for( i = 0 ; i < n ; i++ ) {
            if( k == 0 || k == 1 ) {
                if( str[i] == '1' )
                    k++ ;
                else
                    k = 0 ;
            }
            else {
                if( str[i] == '0' )
                    k++ ;
                else {
                    i = max( 0 , i - 2 ) ;
                    k = 0 ;
                    continue;
                }

                if( k == 4 ) {
                    hash.insert( i - 3 ) ;
                    k = 0 ;
                }
            }

        }
        // cout << "For t = " << t << '\n' ;
        // for( auto& itr : hash )
        //     cout << itr << '\n' ;
        int q;
        cin >> q;
        for( int i = 0 ; i < q ; i++ ) {
            int a ;
            char ch ;
            cin >> a ;
            a-- ;
            cin >> ch ;
            if( n < 4 ) {
                cout << "NO\n" ;
                continue;
            }
            if( str[a] == ch ) {
                cout << ( !hash.empty() ? "YES\n" : "NO\n" ) ;
                continue;
            }
            
            str[a] = ch ;
            for( int j = a ; j >= 0 && j >= a - 3 ; j-- ) {
                if( hash.count( j ) )
                    hash.erase( j ) ;
            }

            int start = max( 0 , a - 3 ) ;
            for( int j = start ; j <= a ; j++ ) {
                if( j + 4 <= n && str.substr( j , 4 ) == "1100" )
                    hash.insert( j ) ;
            }
            cout << ( !hash.empty() ? "YES\n" : "NO\n" ) ;
        }
    }
    return 0;
}