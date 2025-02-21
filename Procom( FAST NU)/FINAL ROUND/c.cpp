#include<bits/stdc++.h>
using namespace std;

int main() {
    int te, th , oe, oh ;
    cin >> te >> th >> oe >> oh ;
    int oT = ( te - oe ) + ( th - oh ) * 2 ;
    if( oT >= 26 )
        cout << "LOLOS\n" ;
    else
        cout << "TIDAK LOLOS\n" ;
    return 0 ;
}