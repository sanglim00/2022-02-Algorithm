#include <iostream>
using namespace std;

int maxSubsequenceSum (int* arr, int num, int& start, int& end) {

    int maxSum = 0, thisSum = 0;
    int gap = end-1;

    start = end-1;
    for(int i = 0, j = 0; j< num; j++) {
        thisSum += arr[j];

        if(thisSum > maxSum) {
            maxSum = thisSum;
            start = i;
            end = j;
            gap = j-i;
        }
        else if(thisSum == maxSum && gap > j-i) {
            if(start <end) start = start+1;
        } 
        else if (thisSum < 0) {
            i = j + 1;
            thisSum = 0;
        }
      
    }
    return maxSum;
}

int main() {
    int times, num, data;
    int start, end;

    cin >> times;
    for(int i = 0; i< times; i++) {
        cin>> num;
        int* arr = new int[num];
        for(int j = 0; j < num; j++) {
            cin>> data;
            arr[j] = data;
        }
        start = 0;
        end = num -1;

        int answer = maxSubsequenceSum(arr, num, start, end);

        if (answer == 0) cout<< answer << " "<< -1 << " "<< -1<<endl;
        else cout<< answer<<" "<< start <<" "<< end <<endl;
    }

    return 0;
}