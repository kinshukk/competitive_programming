#include <bits/stdc++.h>
using namespace std;

string inp;

int dp[100001];

bool isCharacter(char c){
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == ' '){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    //n: any character limit
    //m: latin character limit
    cin >> n >> m;
    //first one for going to next line
    getline(cin, inp);
    getline(cin, inp);

    dp[0] = 0;
    char ch;
    int last_special = 0;

    for(int i=1; i<=inp.size(); i++){
        ch = inp[i-1];
        if(!isCharacter(ch)){
            last_special = i;
            dp[i] = 1 + dp[max(0, i-n)];
        }else{
            dp[i] = 1 + min(dp[ (last_special <= i-m)? i-m : last_special ],
                            dp[max(0, i-n)]);
        }
    }

    cout << dp[inp.size()] << endl;

    return 0;
}
