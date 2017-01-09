#include <bits/stdc++.h>
using namespace std;

struct state{
    int red, black, top;
};

int n;
state dp[1005][1005];
int P1[1005], P2[1005];

bool process(){
    dp[0][0].red = 0;
    dp[0][0].black = 0;
    dp[0][0].top = -1;
    int a = 0, b = 0;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(!i && !j)    continue;

            if(i && dp[i-1][j].top != 0){
                a = dp[i-1][j].red;
                b = dp[i-1][j].black;

                P1[i]? a++ : b++;

                if(abs(a-b) <= 1){
                    dp[i][j].red = a;
                    dp[i][j].black = b;
                    dp[i][j].top = 1;
                    continue;
                }
            }

            if(j && dp[i][j-1].top != 0){
                a = dp[i][j-1].red;
                b = dp[i][j-1].black;

                P2[j]? a++ : b++;

                if(abs(a-b) <= 1){
                    dp[i][j].red = a;
                    dp[i][j].black = b;
                    dp[i][j].top = 2;
                    continue;
                }
            }

            dp[i][j].top = 0;
        }
    }

    if(dp[n][n].top != 0){
        return true;
    }else{
        return false;
    }
}

void print_path(int i, int j){
    if(dp[i][j].top == -1)  return;

    if(dp[i][j].top == 1){
        print_path(i-1, j);
        cout << '1';
    }else{
        print_path(i, j-1);
        cout << '2';
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    string pile1, pile2;

    cin >> n >> pile1 >> pile2;
    for(int i=1; i<=n; i++){
        P1[i] = pile1[i-1]-'0';
        P2[i] = pile2[i-1]-'0';
        //cout << P1[i] << " " << P2[i] << endl;
    }

    if(process()){
        print_path(n, n);
    }else{
        cout << "Impossible" << endl;
    }

    return 0;
}
