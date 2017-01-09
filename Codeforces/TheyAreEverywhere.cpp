#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int l;
    cin >> l;
    string inp;
    cin >> inp;

    map<char, int> m;
    int min_possible_len = 0;

    for(int i=0; i<l; i++){
        char c = inp[i];
        if(m.find(c) == m.end()){
            m[c] = 0;
            ++min_possible_len;
        }
    }

    int lptr = 0, rptr = -1, min_len = 1E6 - 1;
    int cnt = 0;
    bool flag = false;

    //sliding window. expanding the right frontier.
    //contract left frontier if doing so does not
    //affect total types of pokemon caught
    while(rptr < l-1){
        ++rptr;
        char cur = inp[rptr];
        if(m[cur] == 0){
            cnt++;
        }
        m[cur]++;

        while(lptr < rptr){
            if(m[ inp[lptr] ]-1 >= 1){
                m[ inp[lptr] ] -= 1;
                lptr++;
            }else{
                break;
            }
        }
        if(cnt >= min_possible_len){
            flag = true;
        }
        if(flag){
            min_len = min(min_len, rptr-lptr+1);
        }
    }

    //final left frontier contraction
    while(m[ inp[lptr] ]-1 >= 1){
        m[ inp[lptr] ] -= 1;
        lptr++;
        min_len = min(min_len, rptr-lptr+1);
    }

    cout << min_len << endl;
}
