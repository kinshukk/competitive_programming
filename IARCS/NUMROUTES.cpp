//Failing for one test case on IARCS server
#include <iostream>
using namespace std;

const long MOD = 42373;

const int sz = 102;

long adj[sz][sz],
     dest[sz][sz],
     temp[sz][sz];
int src, destination, n;
long k;

void MatrixMultiply(long a[][sz], long b[][sz]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = 0;

            for(int l=0; l<n; l++){
                temp[i][j] += (a[i][l] * b[l][j])%MOD;
                temp[i][j] %= MOD;
            }

        }
    }
}

void MatrixExponent(){
    long p = k;
    while(p > 0){
        if(p&1){
            MatrixMultiply(dest, adj);
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dest[i][j] = temp[i][j];
                }
            }
        }

        MatrixMultiply(adj, adj);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adj[i][j] = temp[i][j];
            }
        }
        p /= 2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> adj[i][j];
        }
    }

    //identity matrix for first multiplication
    for(int i=0; i<n; i++){
        dest[i][i] = 1;
    }

    cin >> src >> destination >> k;
    --src; --destination;

    MatrixExponent();

    if(k == 0){
        cout << 0 << endl;
        return 0;
    }

    cout << dest[src][destination] << endl;

    return 0;
}
