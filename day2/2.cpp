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
    }
    cout << endl;
    // 방법 2 : 스택
    stack<pair<int, int>> s;
    int tmp = A[0];
    for (int i=1; i<n; i++) {
        s.push({A[i], i});
        if (tmp < s.top().first) {
            B[i - 1] = s.top().second;
            s.pop();
            tmp = A[i];
        }
    }
    cout << "stack" << endl;
    for (int i=0; i<n-1; i++) {
        cout << B[i] << " ";
    }
}