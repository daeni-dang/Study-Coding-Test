/*
    1. taskset을 pair로 묶어 vector에 저장
    2. pair의 첫 번째 값 기준으로 정렬
    3. 처음부터 읽으며 역량값이 첫 번째 값보다 크거나 같을 때까지 반복
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, *arr;
    int x = 0;
    cin >> n;
    arr = new int(n * 2);
    for (int i=0; i<n*2; i++) {
        cin >> arr[i];
    }
    vector<pair<int, int>> v;
    for (int i=0; i<n*2; i+=2) {
        v.push_back(make_pair(arr[i], arr[i + 1]));
    }
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        if (x >= v[i].first) {
            x += v[i].second;
        }
    }
    if (x == 0) x = -1;
    cout << x << endl;
}