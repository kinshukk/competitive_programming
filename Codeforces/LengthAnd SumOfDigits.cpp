#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int m, s, digit, cur, remain;
    cin >> m >> s;

    if(s > m*9){
        cout << "-1 -1" << endl;
        return 0;
    }else if(s == 0){
        if(m == 1){
            cout << "0 0" << endl;
        }else{
            cout << "-1 -1" << endl;
        }
        return 0;
    }
    char str1[m], str2[m];
    digit = 1, remain = s;
    while(digit < m){
        if(remain > 9){
            str1[digit-1] = '9';
            remain -= 9;
        }else{
            if(remain > 1){
                str1[digit-1] = '0' + remain-1;
                remain = 1;
            }else{
                str1[digit-1] = '0';
            }
        }
        ++digit;
    }
    str1[digit-1] = '0' + remain;

    remain = s, digit = 1;
    while(digit <= m){
        if(remain > 9){
            remain -= 9;
            str2[digit-1] = '9';
        }else{
            str2[digit-1] = '0' + remain;
            remain = 0;
        }
        ++digit;
    }

    for(int i=m-1; i>=0; i--){
        cout << str1[i];
    }
    cout << " ";
    for(int i=0; i<m; i++){
        cout << str2[i];
    }
    cout << endl;
    return 0;
}
