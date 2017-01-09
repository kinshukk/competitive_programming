#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string inp;
    int l;
    cin >> l >> inp;
    string outp = "";
    bool flag = (l%2 == 0)? false : true;

    for(int i=0; i<l; i++){
        if(flag){
            outp = outp + inp[i];
        }else{
            outp = inp[i] + outp;
        }
        flag = !flag;
    }

    cout << outp << endl;

    return 0;
}
