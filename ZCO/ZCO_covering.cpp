#include <iostream>
#include <algorithm>
using namespace std;

struct interval{
    unsigned long start, end;
};

bool comparator(interval first, interval second){
    if(second.start == first.start){
        return second.end > first.end;
    }else{
        return second.start > first.start;
    }
}

int main(){
    unsigned long n;
    unsigned long j, i;
    cin >> n;
    interval arr[n];
    interval temp;
    for(unsigned long i=0; i<n; i++){
        cin >> temp.start >> temp.end;
        arr[i] = temp;
    }
    sort(arr, arr+n, comparator);

    // for(unsigned long i=0; i<n; i++){
    //     cout << arr[i].start << " " << arr[i].end << endl;
    // }

    unsigned long int count = 1;i = 0; j = 0;
    interval previous_set = arr[0];

    for(i=1; i<n; i = j){
        for(j=i; j<n; j++){
            if(arr[j].start <= previous_set.end){
                if(arr[j].end <= previous_set.end){
                    previous_set = arr[j];//previous set contains the new one
                }else{
                    previous_set.start = arr[j].start;
                }
            }else{
                previous_set = arr[j];
                ++count;
                break;
            }
        }

    }

    cout << count << endl;
}
