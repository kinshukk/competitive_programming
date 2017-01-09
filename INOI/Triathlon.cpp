#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long int ull;

struct t{
    int cobol, other;
};

bool comparator(t first, t second){
    return first.other > second.other;
}

int main(){
    int n, v, d;
    ull minm = 0, timelel = 0, temp = 0;
    cin >> n;
    t arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i].cobol >> v >> d;
        arr[i].other = v+d;
    }
    sort(arr, arr+n, comparator);

    for(int i=0; i<n; i++){
        timelel += arr[i].cobol;
        temp = timelel + arr[i].other;

        if(temp > minm){
            minm = temp;
        }

    }

    cout << minm << endl;
    return 0;
}
