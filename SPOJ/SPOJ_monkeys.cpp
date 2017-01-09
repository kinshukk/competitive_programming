#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int main(){
    int n;
    string st;
    getline(cin, st);
    n = atoi(st.c_str());
    int mx = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        mx = 0, count = 0;
        getline(cin, st);
        for(int j=0; j<st.length(); j++){
            if(st[j] == '['){
                count++;
            }else if(st[j] == ']'){
                count--;
            }
            if(count > mx){
                mx = count;
            }
        }
        printf("%d %d\n", i+1, 1<<mx);

    }

    return 0;
}
