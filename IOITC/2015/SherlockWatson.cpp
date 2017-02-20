#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio( false );

    int t, n;
    cin >> t;

    for( int i=0; i<t; i++ ){
        cin >> n;
        int B[ n ];
        for( int j=0; j<n; j++ ){
            cin >> B[ j ];
        }

        int big[ n ], small[ n ];

        big[ 0 ] = 0;
        small[ 0 ] = 0;

        for( int j=1; j<n; j++ ){
            big[j] = max( big[j-1] + abs(B[j-1] - B[j]),
                               small[j-1] + B[j] - 1 );
            small[j] = max( big[j-1] + B[j-1] - 1,
                               small[j-1] );
        }

        cout << max(big[n-1], small[n-1]) << "\n";
    }

    return 0;
}
