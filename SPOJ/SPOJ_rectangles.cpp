#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;
    for(int i=1; i<=sqrt(n); i++){
        count += floor(n/i) - i + 1;
    }
    cout << count << endl;
    return 0;
}
