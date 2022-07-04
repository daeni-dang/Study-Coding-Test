#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int max = 0, min = 1000000001;
    
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > max)
            max = tmp;
        if (tmp < min)
            min = tmp;
    }
    cout << max - min << endl;
}