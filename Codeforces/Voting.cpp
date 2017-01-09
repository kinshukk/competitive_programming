#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string a;
    cin >> a;
    int d = 0, r = 0;

    while(n != 1){
        int temp_n = n;
        string temp1 = "", temp2 = "";
        r = d = 0;
        for(int i=0; i<n; i++){
            if(a[i] == 'D'){
                if(d > 0){
                    d--;
                }else{
                    temp1 += 'D';
                    r++;
                }
            }else{
                if(r > 0){
                    r--;
                }else{
                    temp1 += 'R';
                    d++;
                }
            }
        }

        for(int i=0; i<temp1.size(); i++){
            if(temp1[i] == 'D'){
                if(d > 0){
                    d--;
                }else{
                    temp2 += 'D';
                }
            }else{
                if(r > 0){
                    r--;
                }else{
                    temp2 += 'R';
                }
            }
        }

        //repetition
        if(a == temp2)  break;

        a = temp2;
        n = temp2.size();
    }

    cout << a[0] << endl;


    return 0;
}
