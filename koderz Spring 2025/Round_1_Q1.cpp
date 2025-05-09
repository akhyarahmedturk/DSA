#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int r) {
    int m = matrix.size() , n = matrix[0].size() ;
    int x1 = 0 , x2 = m - 1 , y1=  0 , y2 = n - 1 ;
    bool r1 = false ;
    if( min( m , n ) == m )
        r1 = true ;
    
    while( ( r1 && x1 < x2 ) || ( y1 < y2 && !r1 ) ) {
        int total = 2 * ( x2 - x1 + 1 ) + 2 * ( y2 - y1 - 1 ) ;
        int r2 = r % total ;
        vector<int> temp( total ) ;
        int s = 0 ;
        for( int i = y2 ; i >= y1 ; i-- )
            temp[s++] = matrix[x1][i] ;
        
        for( int i = x1 + 1 ; i <= x2 ; i++ )
            temp[s++] = matrix[i][y1] ;
        
        for( int i = y1 + 1 ; i <= y2 ; i++ )
            temp[s++] = matrix[x2][i] ;
        
        for( int i = x2 - 1 ; i >= x1 + 1 ; i-- )
            temp[s++] = matrix[i][y2] ;
        
        rotate( temp.begin() , temp.end() - r2 , temp.end() ) ;
        // for( int i = 0 ; i < total ; i++ )
        //     cout << temp[i] << " " ;
        // cout << '\n' ;
        
        s = 0 ;
        for( int i = y2 ; i >= y1 ; i-- )
            matrix[x1][i] = temp[s++] ;
        
        for( int i = x1 + 1 ; i <= x2 ; i++ )
            matrix[i][y1] = temp[s++] ;
        
        for( int i = y1 + 1 ; i <= y2 ; i++ )
            matrix[x2][i] = temp[s++] ;
        
        for( int i = x2 - 1 ; i >= x1 + 1 ; i-- )
            matrix[i][y2] = temp[s++];
        x1++ ; x2-- ; y1++ ; y2-- ;
    }
    
    for( int i = 0 ; i < m ; i++ ) {
        for( int j = 0 ; j < n ; j++ )
            cout << matrix[i][j] << " \n"[j == n - 1] ;
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
