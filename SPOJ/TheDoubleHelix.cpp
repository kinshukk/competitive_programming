#include <iostream>

using namespace std;

int main(){
    int n1, n2, index1, index2;
    int arr1[10000+1], arr2[10000+1];
    long sum1 = 0, sum2 = 0, sum = 0;

    cin >> n1;
    while(n1 > 0){
        index1 = index2 = 0;
        sum1 = sum2 = sum = 0;

        for(int i=0; i<n1; i++){
            cin >> arr1[i];
        }
        cin >> n2;
        for(int i=0; i<n2; i++){
            cin >> arr2[i];
        }

        while(index1 < n1 && index2 < n2){
            if(arr1[index1] == arr2[index2]){
                sum += ((sum1 > sum2)? sum1 : sum2) + arr1[index1];
                sum1 = sum2 = 0;
                ++index1; ++index2;
            }else if(arr1[index1] < arr2[index2]){
                sum1 += arr1[index1];
                ++index1;
            }else{
                sum2 += arr2[index2];
                ++index2;
            }
        }
        while(index1 < n1){
            sum1 += arr1[index1];
            ++index1;
        }
        while(index2 < n2){
            sum2 += arr2[index2];
            ++index2;
        }

        sum += (sum1 > sum2)? sum1 : sum2;

        cout << sum << endl;

        cin >> n1;
    }
}
