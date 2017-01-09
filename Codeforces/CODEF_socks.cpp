#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int arr[m];int t1, t2;
    int count1 = 0, count2 = 0;
    for(int i=0; i<m; i++){
        cin >> t1 >> t2;
        arr[t1]++;
        arr[t2]++;
    }
    //sort(arr, arr + (sizeof(arr))/sizeof(arr[0]));
    for(int i=0; i<m; i++){
        count1 += (int)(arr[m])/2;
        //count2 += arr[m]%2;
    }
    if(count1 >= m){
        cout << 0 << "\n";
    }else{
        int req = m - count1;
        cout << req << "\n";
    }

    return 0;
}
