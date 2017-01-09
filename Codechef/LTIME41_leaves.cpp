#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t = 0;
    cin >> t;
    long long temp1, temp2, temp3, maple = 0, oak = 0, poplar = 0, green = 0, yellow = 0, red = 0, mx = 0;
    for(int i=0; i<t; i++){
        red = 0, yellow = 0, green = 0;
        cin >> temp1 >> temp2 >> temp3;
        maple = temp1 + temp2 + temp3;
        green += temp1;
        yellow += temp2;
        red += temp3;
        cin >> temp1 >> temp2 >> temp3;
        oak = temp1 + temp2 + temp3;
        green += temp1;
        yellow += temp2;
        red += temp3;
        cin >> temp1 >> temp2 >> temp3;
        poplar = temp1 + temp2 + temp3;
        green += temp1;
        yellow += temp2;
        red += temp3;

        mx = max(max(max(red, yellow), max(green, maple)), max(oak, poplar));
        mx = (mx%2 == 0)?((mx != 0)? mx-1 : 0): mx;
        cout << mx << endl;
    }
    return 0;
}
