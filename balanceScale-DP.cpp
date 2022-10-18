#include <iostream>
using namespace std;

#define MAX 10000001; // 모든 자갈의 무게의 총합보다 하나 크게설정

int balanceScale(int* arr, int num) {
    int left = arr[0], right = arr[1];
    
    for(int i = 2; i<num; i++) {
        if(left > right) right += arr[i];
        else left += arr[i];
    }
    return (left > right) ? left-right : right-left;
}

int checkWeight(int& rest){

    int weightArr[] = {1, 2, 5, 10, 20, 50, 100};
    int* usedWeight = new int[rest+1];

    for(int i=0; i<= rest; i++) usedWeight[i] = MAX; 
    
    usedWeight[0] = 0;
    
    for(int i=0; i< 7; i++){
        for(int j = weightArr[i]; j <= rest; j++){
            int checkMin = min(usedWeight[j], usedWeight[j - weightArr[i]] + 1);
            usedWeight[j] = checkMin;
        }
    }

    return usedWeight[rest];
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
