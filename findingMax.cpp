#include <iostream>
using namespace std;

int recursiveMax(int* arr, int left, int right) {
    int half;

    if(left == right) return arr[left];
    else {
        half = (left + right) / 2;
        
        int sectionL = recursiveMax(arr, left, half);
        int sectionR = recursiveMax(arr, half+1, right);

        return max(sectionL, sectionR);
    }
}

int main() {
    int times, num;

    cin >> times;
    for(int i = 0; i< times; i++) {
        cin >> num;
        int* arr = new int[num];
        for(int j = 0; j< num; j++) {
            int data ;
            cin >> data;
            arr[j] = data;
        }
        int answer = recursiveMax(arr, 0, num-1);
        cout<< answer <<endl;
    }

    return 0;
}