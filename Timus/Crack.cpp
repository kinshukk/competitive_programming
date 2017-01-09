#include <bits/stdc++.h>
using namespace std;

long dp[10001], words[10001];

bool isLetter(char ch){
    int c = (int)ch;
    if( (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    words[0] = 0;
    int i = 0;
    string inp = "";
    char in;
    while(in = getchar()){
        if(in <= 0) break;

        if(isLetter(in)){
            inp += in;
        }else{
            if(inp.size() > 0){
                ++i;
                words[i] = inp.size();
            }
            inp = "";
        }

    }

    int l = i;
    dp[0] = 0;
    dp[1] = words[1];

    for(i=2; i<=l; i++){
        dp[i] = max(words[i] + dp[i-2], dp[i-1]);
    }
    cout << dp[l] << endl;

    return 0;
}
