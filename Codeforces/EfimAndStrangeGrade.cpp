#include <bits/stdc++.h>
using namespace std;

const int INFIN = INT_MAX - 1;

int main(){
    ios_base::sync_with_stdio(false);
    int n, t, i;
    bool crossed = false;
    string grade;
    cin >> n >> t;
    cin >> grade;
    for(i=0; i<n && grade[i] != '.'; i++);

    for(;i<n; i++){
        if(grade[i] > '4'){
            break;
        }
    }

    if(i < n){
        for(; t>0 && grade[i] > '4'; i--, t--){
            if(grade[i-1] == '.'){
                grade[i-2]++;
                crossed = true;
                break;
            }else{
                grade[i-1]++;
            }
        }
    }else{
        i--;
    }

    if(crossed){
        for(i=i-2; i>0 && grade[i] > '9'; i--){
            grade[i] = '0';
            grade[i-1]++;
        }
        if(i==0 && grade[0] > '9'){
            cout << '1';
            grade[0] = '0';
        }
        for(int i=0; grade[i] != '.'; i++){
            cout << grade[i];
        }
    }else{
        for(t=0; t<=i; t++){
            cout << grade[t];
        }
    }
    cout << endl;

    return 0;
}
