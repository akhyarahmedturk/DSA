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
        int n , m ;
        cin >> n >> m ;
        int u = 0 , r = m - 1 , d = n - 1 , l = 0 ;
        vector<vector<char>> mat( n , vector<char>( m ) ) ;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                cin>>mat[i][j];
            }
        }
        vector<string> vec;
        while( u <= d && l <= r ) {
            string temp="";
            // cout << u << " " << d << " " << l << " " << r << '\n';
            for( int i = l ; i <= r ; i++ ) {
                temp+=mat[u][i];
            }
            u++ ;
            for( int i = u ; i <= d ; i++ ) {
                temp+=mat[i][r];
            }
            r-- ;
            for( int i = r ; i >= l ; i-- ) {
                temp+=mat[d][i];
            }
            d-- ;

            for( int i = d ; i >= u ; i-- ) {
                temp+=mat[i][l];
            }
            l++ ;
            temp+=temp.substr(0,3);
            vec.push_back(temp);
        }
        int count=0;
        for(int i=0;i<vec.size();i++){
            for( int j = 0 ; j < vec[i].length() - 3 ; j++ ) {
                if( vec[i].substr( j , 4 ) == "1543" )
                    count++ ;
            }
        }
        cout << count << '\n' ;
    }
    return 0;
}