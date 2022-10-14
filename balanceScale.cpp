#include <iostream>
using namespace std;

int balanceScale(int* arr, int num) {
    int left = arr[0], right = arr[1];
    
    for(int i = 2; i<num; i++) {
        if(left > right) right += arr[i];
        else left += arr[i];
    }
    return (left > right) ? left-right : right-left;
}

int checkWeight(int& rest) {
    int cnt = 0;
    int weightArr[7] = {100, 50, 20, 10, 5, 2, 1};

    for(int i = 0; i < 7; i++) {
        if(rest >= weightArr[i]) {
            cnt += rest / weightArr[i];
            rest %= weightArr[i];
        }
    }

    return cnt;
}


int main() {
    int times, num, data;

    cin>>times;

    for(int i = 0; i< times; i++) {
        cin >>num;
        int* arr = new int[num];
        for(int j = 0; j<num; j++) {
            cin>> data;
            arr[j] = data;
        }
        int answer = balanceScale(arr, num);
        if(answer != 0) answer = checkWeight(answer);

        cout<< answer <<endl;
    }


    return 0;
}
