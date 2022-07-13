// T-3. 동빈이 떡집

/*
    1. 입력받은 배열에서 최댓값 찾기
    2. 최댓값으로 절단기 길이 이진탐색하며 찾기
    
*/

#include <iostream>
using namespace std;

int main() {
    int n, m, max = 0;
    cin >> n >> m;
    int *h = new int(n);
    for (int i=0; i<n; i++) {
        cin >> h[i];
        if (h[i] > max)
            max = h[i];
    }
    int start = 0, end = max;
    int cutter = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        int sum = 0;
        for (int i=0; i<n; i++) {
            if (h[i] > mid) {
                sum += (h[i] - mid);
            }
        }
        if (sum < m) {
            end = mid - 1;
        }
        else {
            cutter = mid;
            start = mid + 1;
        }
    }
    cout << cutter << endl;
}