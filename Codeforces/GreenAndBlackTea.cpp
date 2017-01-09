#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    if(a == 0){
        if(k >= b){
            for(int i=0; i<b; i++){
                cout << 'B';
            }
        }else{
            cout << "NO" << endl;
        }
    }else if(b == 0){
        if(k >= a){
            for(int i=0; i<a; i++){
                cout << 'G';
            }
        }else{
            cout << "NO" << endl;
        }
    }else if(max(a,b)/min(a, b) > k){
        cout << "NO" << endl;
    }else{
        string outp = "";
        int prev = (a > b)? 0 : 1;
        int cnt = 0;
        while(a > 0 || b > 0){
            if(prev){
                if(b < a){
                    b -= 1;
                    cnt = 1;
                }else{
                    if(b-k < 0){
                        cnt = b;
                        b = 0;
                    }else{
                        b = b-k;
                        cnt = k;
                    }
                }
                for(int i=0; i<cnt; i++){
                    outp += "B";
                }
            }else{
                if(a < b){
                    a -= 1;
                    cnt = 1;
                }else{
                    if(a-k < 0){
                        cnt = a;
                        a = 0;
                    }else{
                        a -= k;
                        cnt = k;
                    }
                }
                for(int i=0; i<cnt; i++){
                    outp += "G";
                }
            }
            prev = (prev + 1)%2;
        }

        cout << outp << endl;
    }

    return 0;
}
