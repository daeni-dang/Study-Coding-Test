/*
    1. 이진 탐색으로 x의 시작 인덱스 찾기
    2. x의 끝 인덱스 찾기
*/

#include <iostream>
using namespace std;

int bs_front(int arr[], int x, int n);
int bs_back(int arr[], int x, int n);

int main() {
    int n, x;
    cin >> n >> x;
    int *arr = new int(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int start = bs_front(arr, x, n);
    int end = bs_back(arr, x, n);
    cout << start << ", " << end << endl;
    if (start == -1 || end == -1) {
        cout << -1 << endl;
    }
    else cout << end - start << endl;
}

int bs_front(int arr[], int x, int n) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] >= x)
            end = mid - 1;
        else if (arr[mid] < x)
            start = mid + 1;
        else {
            if (mid - 1 < 0 || arr[mid - 1] != x)
                return mid;
            end = mid - 1;
        }
    }
    return -1;
}

int bs_back(int arr[], int x, int n) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] >= x)
            end = mid - 1;
        else if (arr[mid] < x)
            start = mid + 1;
        else {
            if (mid + 1 >= n || arr[mid + 1] != x)
                return mid;
            start = mid + 1;
        }
    }
    return -1;
}