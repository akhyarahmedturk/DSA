int pickingNumbers(vector<int> a) {
    int n = a.size() ;
    sort( a.begin() , a.end() ) ;
    
    if( abs( a[0] - a.back() ) <= 1 )
        return n ;
    
    vector<pair<int,int>> s ;
    
    s.push_back( { a[0] , 0 } ) ;
    int count = 1 ;
    for( int i = 1 ; i < n ; i++ ) {
        if( a[i] != a[i - 1] ) {
            // cout << i << "\n" ;
            if( s.size() == 1 )
                count = i + 1 ;
            else if( s.size() >= 2 ) {
                if( s[ s.size() - 1 ].first == s[ s.size() - 2 ].first + 1 )
                    count = max( count , i - s[ s.size() - 2 ].second ) ;
                else
                    count = max( count , i - s[ s.size() - 1 ].second ) ;
            }
            s.push_back( { a[i] , i } ) ;

        }
        
        
    }
    
    if( s[ s.size() - 1 ].first == s[ s.size() - 2 ].first + 1 )
        count = max( count , n - s[ s.size() - 2 ].second ) ;
    else
        count = max( count , n - s[ s.size() - 1 ].second ) ;
    
    return count ;
}