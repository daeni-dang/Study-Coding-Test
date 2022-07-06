#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *A = new int(n);
    int *B = new int(n - 1);
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }
    // 방법 1 : 2중 반복문
    for (int i=0; i<n - 1; i++) {
        for (int j=i+1; j<n; j++) {
            if (A[i] < A[j]) {
                B[i] = j;
                break;
            }
        }
    }
    cout << "for" << endl;
    for (int i=0; i<n-1; i++) {
        cout << B[i] << " ";
        B[i] = 0;
    }
    cout << endl;
    // 방법 2 : 스택
    stack<pair<int, int>> s;
    int b_idx = 0;
    int tmp = A[0];
    int i = 1;
    while (b_idx < n - 1) {
        s.push({A[i], i});
        i++;
        if (tmp < s.top().first) {
            B[b_idx++] = s.top().second;
            s.pop();
            tmp = A[b_idx];
            i = b_idx;
        }
    }
    cout << "stack" << endl;
    for (int i=0; i<n-1; i++) {
        cout << B[i] << " ";
    }
}