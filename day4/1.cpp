#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    vector<int> n_v;
    vector<int> m_v;
    int max = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        n_v.push_back(tmp);
        if (tmp > max)
            max = tmp;
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        int tmp;
        cin >> tmp;
        m_v.push_back(tmp);
    }
    int *arr = new int(max - 1);
    for (int i=0; i<n; i++) {
        arr[n_v[i] - 1] = 1;
    }
    for (int i=0; i<m; i++) {
        if (arr[m_v[i] - 1] == 1)
            cout << "yes" << " ";
        else
            cout << "no" << " ";
    }
}