#include <iostream>
#include <vector>
using namespace std;

int main(){
    unsigned int n, m;
    cin >> n >> m;
    if(n>m){
        int temp = n;
        n = m;
        m = temp;
    }
    int tempn = n, tempm = m;
    int pet1 = 0, vas1 = 0, pet2 = 0, vas2 = 0;
    int chance = 0; //0 for petya 1 for vasya
    vector<int> arr;
    int index = 0;

    if(n==1){
        arr.push_back(0);
        index++;
        n--;
        chance = 1;
    }else if(n>0){
        arr.push_back(1);
        index++;
        m--;
        chance = 1;
    }
    while(n > 0 && m > 0){
        if(chance == 0){
            if(arr[index-1] == 0){
                arr.push_back(0);
                n--;
            }else{
                arr.push_back(1);
                m--;
            }
        }else{
            if(arr[index-1] == 1){
                arr.push_back(0);
                n--;
            }else{
                arr.push_back(1);
                m--;
            }
        }
        index++;
        chance = (chance+1)%2;
    }

    if(n > 0){
        for(int i=0; i<n; i++){
            arr.push_back(0);
        }
        n = 0;
    }

    if(m > 0){
        for(int i=0; i<m; i++){
            arr.push_back(1);
        }
    }

    for(int i=0; i<arr.size()-1; i++){
        if(arr[i] == arr[i+1]){
            pet1++;
        }else{
            vas1++;
        }
    }


    n = tempn, m = tempm;
    arr.clear();
    chance = 0;
    index = 0;
    if(n==1){
        arr.push_back(1);
        index++;
        n--;
        chance = 1;
    }else if(n>0){
        arr.push_back(0);
        index++;
        m--;
        chance = 1;
    }
    while(n > 0 && m > 0){
        if(chance == 0){
            if(arr[index-1] == 0){
                arr.push_back(0);
                n--;
            }else{
                arr.push_back(1);
                m--;
            }
        }else{
            if(arr[index-1] == 1){
                arr.push_back(0);
                n--;
            }else{
                arr.push_back(1);
                m--;
            }
        }
        index++;
        chance = (chance+1)%2;
    }

    if(n > 0){
        for(int i=0; i<n; i++){
            arr.push_back(0);
        }
        n = 0;
    }

    if(m > 0){
        for(int i=0; i<m; i++){
            arr.push_back(1);
        }
    }

    for(int i=0; i<arr.size()-1; i++){
        if(arr[i] == arr[i+1]){
            pet2++;
        }else{
            vas2++;
        }
    }
    cout << pet1 << " " << vas1 << " " << pet2 << " " << vas2 << endl;
    if(pet1<pet2){
        cout << pet2 << " " << vas2 << endl;
    }else{
        cout << pet1 << " " << vas1 << endl;
    }
    return 0;
}
