#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1E9;

int main(){
    ios_base::sync_with_stdio(false);
    long long src[2][2], dest[2][2], temp[2][2];
    src[1][0] = src[0][1] = src[1][1] = dest[0][0] = dest[1][1] = 1;
    src[0][0] = dest[1][0] = dest[0][1] = 0;

    long long n;
    cin >> n;

    if(n <= 2){
        cout << 1 << endl;
    }else{
        n -= 2;

        long long num_steps = 0;

        while(n > 0){
            if(n & 1){
                for(int i=0; i<2; i++){
                    for(int j=0; j<2; j++){
                        temp[i][j] = 0;
                        for(int k=0; k<2; k++){
                            temp[i][j] += ( src[k][i] * dest[j][k] ) % MOD;
                            temp[i][j] %= MOD;
                        }
                    }
                }

                for(int i=0; i<2; i++){
                    for(int j=0; j<2; j++){
                        dest[i][j] = temp[i][j];
                    }
                }
            }

            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++){
                    temp[i][j] = 0;
                    for(int k=0; k<2; k++){
                        temp[i][j] += ( src[k][i] * src[j][k] ) % MOD;
                        temp[i][j] %= MOD;
                    }
                }
            }

            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++){
                    src[i][j] = temp[i][j];
                }
            }

            num_steps++;
            n /= 2;
        }

        long long outp = 0;
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                outp += dest[i][j];
                outp %= MOD;
            }
        }

        cout << outp << endl;
        cout << "number of steps = " << num_steps << endl;
    }

    return 0;
}
