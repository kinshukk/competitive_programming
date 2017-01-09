#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    long mat[n][n];
    //j: x; i: y
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }

    ll major_diags[n*2 - 1], minor_diags[n*2 - 1];
    for(int i=0; i<2*n-1; i++){
        major_diags[i] = minor_diags[i] = 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            major_diags[i+j] += mat[i][j];
            minor_diags[i-j+n-1] += mat[i][j];
        }
    }

    // for(int i=0; i<2*n-1; i++){
    //     cout << major_diags[i] << " " << minor_diags[i] << endl;
    // }

    int fx=0, fy=0, sx=0, sy=0;
    ll max1 = -1, max2 = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((i+j)%2 == 0){
                if(major_diags[i+j] + minor_diags[i-j+n-1] - mat[i][j] > max1){
                    max1 = major_diags[i+j] + minor_diags[i-j+n-1] - mat[i][j];
                    fx = i;
                    fy = j;
                }
            }else{
                if(major_diags[i+j] + minor_diags[i-j+n-1] - mat[i][j] > max2){
                    max2 = major_diags[i+j] + minor_diags[i-j+n-1] - mat[i][j];
                    sx = i;
                    sy = j;
                }
            }
        }
    }

    cout << max1 + max2 << endl;
    cout << fx+1 << " " << fy+1 << " " << sx+1 << " " << sy+1 << " " << endl;
    return 0;
}
