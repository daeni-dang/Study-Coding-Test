#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int result = 0;
    for (char c : s) {
        if (result == 0 || result == 1 || c == '1') {
            result += (c - '0');
        }
        else {
            result *= (c - '0');
        }
    }
    cout << result << endl;
}