/*
    방법 1
    1. 정렬
    2. 원소 하나씩 스캔
        2-1. 모험가수 증가
        2-2. 모험가수와 현재 원소 비교
            2-2-1. 현재 원소가 모험가수 비교
            2-2-2. 크면 모험가수 증가
            2-2-3. 작다면 그룹수 증가
    방법 2
    1. n 크기의 배열(tmp) 생성 및 0으로 초기화
    2. tmp에 모험가 공포도 인덱스 증가
    3. tmp 스캔
        3-1. tmp 원소 / tmp 인덱스 + 1 ==> 그룹 수
        3-2. tmp 원소 % tmp 인덱스 + 1 ==> 잉여 모험가 수
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    // 방법 1 : 정렬(O(nlogn))
    sort(arr, arr + n);
    int adven = 0, group = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] > adven)
            adven++;
        if (arr[i] <= adven) {
            group++;
            adven = 0;
        }
    }
    cout << "sort" << endl;
    cout << group << endl;
    // 방법 2 : 배열(O(n))
    int *tmp_arr = new int(n);
    for (int i=0; i<n; i++) {
        tmp_arr[i] = 0;
    }
    for (int i=0; i<n; i++) {
        tmp_arr[arr[i] - 1]++;
    }
    int adven2 = 0, group2 = 0;
    for (int i=0; i<n; i++) {
        group2 += (adven2 + tmp_arr[i]) / (i + 1);
        adven2 = tmp_arr[i] % (i + 1);
    }
    cout << "array" << endl;
    cout << group2 << endl;
}