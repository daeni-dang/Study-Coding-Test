/*
   1. food_times 벡터에 pair로 저장 <food_time, 인덱스>
    2. food_time을 기준으로 내림차순 정렬
    3. k가 food_times의 길이보다 크거나 같을동안 반복
        3-1. k에서 (food_times의 가장 작은 원소 * food_times의 길이) 빼기
        3-2. food_times의 food_time 3-1 값만큼 빼기
        3-3. food_time이 0이라면 pop
        3-4. food_times의 길이가 0이라면 더 이상 먹을 것이 없으므로 -1
    4. 남은 k값 처리

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
    int k, answer = 0;
    cin >> k;
    vector<int> food_times;
    vector<pair<int, int>> pair_food_times;
    int idx = 1, eat_idx = 0;
    while (1) {
        int f_time;
        cin >> f_time;
        if (f_time == -1)  break;
        food_times.push_back(f_time);
    }
    for (int i=0; i<food_times.size(); i++) {
        pair_food_times.push_back(make_pair(food_times[i], i + 1));
    }
    sort(pair_food_times.rbegin(), pair_food_times.rend());
    while (k >= pair_food_times.size() * pair_food_times[pair_food_times.size() - 1].first) {
        if (pair_food_times.empty()) {
            cout << -1 << endl;
            return -1;
        }
        k -= pair_food_times[pair_food_times.size() - 1].first * pair_food_times.size();
        int min = pair_food_times[pair_food_times.size() - 1].first;
        int len = pair_food_times.size();
        for (int i=len - 1; i>=0; i--) {
            pair_food_times[i].first -= min;
            if (pair_food_times[i].first == 0)
                pair_food_times.pop_back();
        }
    }
    sort(pair_food_times.begin(), pair_food_times.end(), compare);
    answer = (long long)pair_food_times[k % pair_food_times.size()].second;
    cout << answer << endl;
}