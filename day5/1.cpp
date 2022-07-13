//  T-3. 떡볶이 떡
/*
    1. 최댓값 찾기
    2. 떡 개수 배열 tteok 생성
    3. 최댓값(절단기 높이)부터 1씩 감소시키면서 tteok에 잘린 길이 저장
    4. 잘린 길이 다 더해서 sum pair vector에 {절단기 높이, 잘린 길이 합}저장
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int *h = new int(n);
    int *tteok = new int(n);
    for (int i=0; i<n; i++) {
        cin >> h[i];
    }
    int max = 0;
    for (int i=0; i<n; i++) {
        if (h[i] > max)
            max = h[i];
    }
    while (max >= 0) {
        int sum = 0;
        for (int i=0; i<n; i++) {
            if (h[i] - max >= 0)
                tteok[i] = h[i] - max;
            else tteok[i] = 0;
            sum += tteok[i];
        }
        if (sum >= m) {
            cout << max << endl;
            break;
        }
        max--;
    }
}