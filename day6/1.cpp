//  Q-1. 연속 상승, 하락

/*
    1. 배열 순차 탐색
    2. 다음 수 - 현재 수 < 0 -> 내림차순
        2-1. 이전 값과 비교하여 같으면 내림차순 개수 증가
        2-2. 이전 값과 다르면 내림차수 개수 1
        2-3. ac 값 벡터에 저장
    3. 다음 수 - 현재 수 > 0 -> 오름차순
        3-1. 이전 값과 비교하여 같으면 오름차순 개수 증가
        3-2. 이전 값과 다르면 오름차수 개수 1
        3-3. de값 벡터에 저장
    4. ac, de 벡터 탐색하면서 최댓값 찾아 출력
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr;
    vector<int> ac_arr;
    vector<int> de_arr;
    while (1) {
        int n;
        cin >> n;
        if (n == -1)
            break;
        arr.push_back(n);
    }
    if (arr.size() == 1) {
        cout << 1 << endl;
        exit(0);
    }
    int dif = arr[1] - arr[0];
    int ac = 1, de = 1;
    bool flag = true; // true: 오름차순, false: 내림차순
    for (int i=0; i<arr.size()-1; i++) {
        if (arr[i + 1] - arr[i] > 0) {  // 오름차순
            if (!flag)  de = 1;
            ac++;
            flag = true;
            ac_arr.push_back(ac);
        }
        else if (arr[i + 1] - arr[i] < 0) {
            if (flag)   ac = 1;
            de++;
            flag = false;
            de_arr.push_back(de);
        }
        else {
            ac_arr.push_back(ac);
            de_arr.push_back(de);
            ac = 1; de = 1;
        }
    }
    int ac_idx = 0, de_idx = 0;
    int ac_max = 0, de_max = 0;
    int cnt = 0;
    while (ac_idx < ac_arr.size() || de_idx < de_arr.size()) {
        if (ac_idx < ac_arr.size()) {
            if (ac_arr[ac_idx] > ac_max)
                ac_max = ac_arr[ac_idx];
            ac_idx++;
        }
        if (de_idx < de_arr.size()) {
            if (de_arr[de_idx] > de_max)
                de_max = de_arr[de_idx];
            de_idx++;
        }
    }
    if (ac_max <= 2) ac_max = 1;
    if (de_max <= 2) de_max = 1;
    cout << ac_max << " " << de_max << endl;