#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int s, x1, x2, t1, t2, pos, d;
    cin >> s >> x1 >> x2 >> t1 >> t2 >> pos >> d;

    float ans = 0;

    if(t2 <= t1){
        ans = abs(x2 - x1) * t2;
    }else{
        int ans2 = 0;
        if(x1 == x2){
            ans = 0;
        }else{
            if(x1 > x2){
                swap(x1, x2);
                d = -d;
                pos = (s - pos);
            }

            if(d = -1){
                float meet = ( (t1 * pos) - (t2 * x2) ) / (t2 + t1);
                cout << meet << endl;
                if(meet >= x2 || meet < x1){
                    ans = (float)abs(x2 - x1) * t2;
                }else{
                    ans = ((meet - x1) * t2) + ((float)x2-meet)*t1;
                    ans = min(ans, (float)t2*( abs(x2-x1) ));
                }
            }else{
                if(pos > x1){
                    float meet = (( (float)t2*x1) + t1*(2*s - (float)pos)) / ((float)t2 - t1);
                    cout << meet << endl;
                    if(meet <= x1 || meet >= x2){
                        ans = t2*( (float)abs(x2-x1) );
                    }else{
                        ans = t2*( (float)abs(x2-x1) );
                        ans = min(ans, (meet - x1)*t2 + (x2 - meet)*t1);
                    }
                }else{
                    ans = min(t2*( (float)abs(x2-x1) ), t1 * (float)(x2-pos) );
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
