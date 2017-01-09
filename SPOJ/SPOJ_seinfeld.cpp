#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    string inp;
    getline(cin, inp);
    int count = 0, ext = 0, n = 1, outp = 0;;
    while(inp[0] != '-'){
        count = 0;
        ext = 0;
        for(int i=0; i<inp.length(); i++){
            if(inp[i] == '}'){
                if(count <= 0){
                    ext ++;
                }else{
                    count--;
                }
            }else if(inp[i] == '{'){
                count++;
            }
        }

        outp = (count + ext)/2;

        if(count > 0 && ext > 0){
            outp++;
        }

        printf("%d. %d\n", n, outp);
        n++;
        getline(cin, inp);
    }
    return 0;
}
