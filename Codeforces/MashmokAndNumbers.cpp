#include <bits/stdc++.h>
using namespace std;

bool done[(int)1E5 + 10];

int main(){
    int n, k;
    cin >> n >> k;

    if(n == 1){
        cout << ( (k == 0)? 1 : -1 );
    }else{
        if(k < ( n / 2) ){
            cout << -1 << endl;
            return 0;
        }

        fill(done, done+(int)(1E5 + 1), false);

        int t = k - (n-2)/2;
        cout << t << " " << 2*t << " ";
        if(t <= 1E5)    done[t] = true;
        if(2*t <= 1E5)  done[2*t] = true;
        n = n-2;


        int cnt = 1;
        while(n > 1){
            while(done[cnt] || done[cnt+1]){
                cnt++;
            }
            done[cnt] = true;
            done[cnt+1] = true;
            cout << cnt << " " << cnt+1 << " ";
            cnt += 2;
            n -= 2;
        }

        if(n == 1){
            for(int i=1; i<=(int)1E5+1; i++){
                if(!done[i]){
                    cout << i << endl;
                    break;
                }
            }
        }
    }
}
