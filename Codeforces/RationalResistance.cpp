#include <bits/stdc++.h>
using namespace std;

//number of resistors required is number of steps
//in euclidean algorithm for finding GCD of two numbers
//this is because with unit resistors,
//if using k resistors we have a ratio a/b,
//then by using k+1 resistors we can have
//ratio (a+b)/b (in series with new unit resistor) 
//or a/(a+b) (in parallel with new unit resistor)
long long count_resistors(long long a, long long b){
    long long step_count = 0;
    while(a > 0 && b > 0){
        if(a <= b && a != 0){
            step_count += b/a;
            b %= a;
        }
        if(b <= a && b != 0){
            step_count +=  a/b;
            a %= b;
        }
    }
    return step_count;
}

int main(){
    ios_base::sync_with_stdio(false);
    long long n1, n2;

    cin >> n1 >> n2;

    cout << count_resistors(n1, n2) << endl;

    return 0;
}
