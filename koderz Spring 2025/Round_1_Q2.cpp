#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int palindromeIndex(string s) {
    int n = s.length() ;
    int j = 0 , k = n - 1 ;
    
    while( j <= k && s[j] == s[k] ) {
        j++ ;
        k-- ;
    }
    
    if( j > k ) return -1 ;
    
    vector<int> hash( 26 , 0 ) ;
    for( char& ch : s )
        hash[ ch - 'a' ]++ ;
    
    int cnt = 0 ;
    for( int i = 0 ; i < 26 ; i++ ) {
        if( hash[i] & 1 ) {
            cnt++ ;
                char ch = 'a' + i ;
                int l = 0 , r = n - 1 ;
                bool f = true ; bool a = true ;
                int ans = 0 ;
                while( l < r ) {
                    if( s[l] == s[r] ) {
                        l++ ;
                        r-- ;
                    }
                    else if( !f ) {
                        a = false ;
                        break ;
                    }
                    else {
                        if( s[l] == ch ) {
                            l++ ;
                            ans = l - 1 ;
                            f = false ;
                        }
                        else if( s[r] == ch ) {
                            ans = r ;
                            r-- ;
                            f = false ;
                        }
                        else {
                            a = false ;
                            break ;
                        }
                    }
                }
                
                if( a )
                    return ans ;
        }
    }
    return -1 ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

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
