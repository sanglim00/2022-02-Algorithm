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

int checkWeight(int rest) {
    int count = 0;

    while(rest != 0) {
        if(rest / 100 !=0) {
            rest %= 100;
            count++;
        }
        if(rest / 50 !=0) {
            rest %= 50;
            count++;
        }
        if(rest / 20 !=0) {
            rest %= 20;
            count++;
        }
        if(rest / 10 !=0) {
            rest %= 10;
            count++;
        }
        if(rest / 5 !=0) {
            rest %= 5;
            count++;
        }
        if(rest / 2 !=0) {
            rest %= 2;
            count++;
        }
        if(rest / 1 !=0) {
            rest %= 1;
            count++;
        }
    }
    return count;
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