// P-1. cost보다 작은 가장 연속된 길이

/*
    1. 시작 인덱스 0으로 설정
    2. 배열을 끝까지 탐색(끝 인덱스)
    3. 배열 원소를 sum에 더함
    4. sum이 cost보다 작다면 현재 인덱스+1-시작 인덱스 값 벡터에 저장
    5. sum이 cost보다 크다면 시작 인덱스에 해당하는 값 sum에서 뺄셈
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