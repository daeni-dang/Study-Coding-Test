// P-1. 

/*
    1. 배열 처음부터 
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cost;
    vector<int> arr;
    cin >> cost;
    while (1) {
        int n;
        cin >> n;
        if (n == -1) break;
        arr.push_back(n);
    }
    vector<int> sum_arr;
    int sum = 0;
    int sidx = 0;
    for (int i=0; i<arr.size(); i++) {
        sum += arr[i];
        if (sum <= cost)
            sum_arr.push_back(i + 1 - sidx);
        else
            sum -= arr[sidx++];
    }
    int max = 0;
    for (int i=0; i<sum_arr.size(); i++) {
        if (sum_arr[i] > max)
            max = sum_arr[i];
    }
    if (sum_arr.size() == 0)
        max = 0;
    cout << max << endl;
}