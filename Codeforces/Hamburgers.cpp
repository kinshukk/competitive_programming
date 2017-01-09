#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int nb, ns, nc, pb, ps, pc;
    unsigned long long rub, num_burgers;

    cin >> s;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> rub;

    int freq_s = 0, freq_b = 0, freq_c = 0;
    for(int i=0; i<s.size(); i++){
        switch(s[i]){
            case 'B':
                freq_b++;
                break;
            case 'S':
                freq_s++;
                break;
            case 'C':
                freq_c++;
        }
    }

    if(freq_b == 0){
        nb = 0;
    }
    if(freq_s == 0){
        ns = 0;
    }
    if(freq_c == 0){
        nc = 0;
    }

    unsigned long long single_burger_price = freq_b * pb +
                                             freq_c * pc +
                                             freq_s * ps,
                       spent = 0;

    num_burgers = 0;
    while(rub > 0){
        if(nb == 0 && ns == 0 && nc == 0){
            num_burgers += rub / single_burger_price;
            break;
        }else{
            int price_b_this, price_s_this, price_c_this;
            if(freq_b <= nb){
                nb -= freq_b;
                price_b_this = 0;
            }else{
                price_b_this = (freq_b - nb)*pb;
                nb = 0;
            }

            if(freq_s <= ns){
                ns -= freq_s;
                price_s_this = 0;
            }else{
                price_s_this = (freq_s - ns)*ps;
                ns = 0;
            }

            if(freq_c <= nc){
                nc -= freq_c;
                price_c_this = 0;
            }else{
                price_c_this = (freq_c - nc)*pc;
                nc = 0;
            }

            price_b_this = price_b_this + price_c_this + price_s_this;

            if(price_b_this <= rub){
                rub -= price_b_this;
                num_burgers++;
            }else{
                break;
            }
        }
        //cout << nb << " " << nc << " " << ns << " " << rub << " " << num_burgers << endl;
    }

    cout << num_burgers << endl;

}
