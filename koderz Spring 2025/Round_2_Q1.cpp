int minimumMoves(vector<string> grid, int X, int Y, int goalX, int goalY) {
    int n=grid.size();
    vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
    dist[X][Y] = 0 ;
    priority_queue<pair<pair<int,int>,int>> pq;
    pq.push({{X,Y},0}) ;
        
    while( !pq.empty() ) {
        int x = pq.top().first.first , y = pq.top().first.second ;
        int d = pq.top().second ;
        pq.pop() ;
        
        if( d > dist[x][y] ) continue ;
        
        for( int i = x + 1 ; i < n && grid[i][y] != 'X' ; i++ ) {
            if( d + 1 < dist[i][y] ) {
                dist[i][y] = d + 1 ;
                pq.push( { { i , y } , d + 1 } ) ;
            }
        }
        
        for( int i = x - 1 ; i >= 0 && grid[i][y] != 'X' ; i-- ) {
            if( d + 1 < dist[i][y] ) {
                dist[i][y] = d + 1 ;
                pq.push( { { i , y } , d + 1 } ) ;
            }
        }
        
        for( int i = y - 1 ; i >= 0 && grid[x][i] != 'X' ; i-- ) {
            if( d + 1 < dist[x][i] ) {
                dist[x][i] = d + 1 ;
                pq.push( { { x , i } , d + 1 } ) ;
            }
        }
        
        for( int i = y + 1 ; i < n && grid[x][i] != 'X' ; i++ ) {
            if( d + 1 < dist[x][i] ) {
                dist[x][i] = d + 1 ;
                pq.push( { { x , i } , d + 1 } ) ;
            }
        }
    }
    
    return dist[goalX][goalY] ;
}