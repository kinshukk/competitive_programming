#include <iostream>
 using namespace std;

 int main(){
     int d, sum_time, min_sum, max_sum, inp1, inp2;
     cin >> d >> sum_time;
     min_sum = max_sum = 0;
     pair<int, int> arr[d];
     for(int i=0; i<d; i++){
         cin >> arr[i].first >> arr[i].second;
         min_sum += arr[i].first;
         max_sum += arr[i].second;
     }

     if(sum_time >= min_sum && sum_time <= max_sum){
         cout << "YES\n";
         for(int j=0; j<d; j++){
             int i=arr[j].first;
             while(i < arr[j].second && sum_time-i > min_sum-arr[j].first){
                 ++i;
             }
             sum_time -= i;
             min_sum -= arr[j].first;
             cout << i << " ";
         }
         cout << endl;
     }else{
         cout << "NO" << endl;
     }
     return 0;
 }
