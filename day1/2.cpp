#include <iostream>
using namespace std;

int main() {
    int n, m;
    int max = 0;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int min = 10001;
        for (int j=0; j<m; j++) {
            int tmp;
            cin >> tmp;
            if (tmp < min) {
                min = tmp;
            }
        }
        if (min > max) {
            max = min;
        }
    }
    cout << max << endl;
}