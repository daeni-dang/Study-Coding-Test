// P-2. 1로 만들기

/*
    ## dynamic programming ##

    n(x) : 정수 x를 1로 만드는 최소 연산 횟수
    n(x) = min{ n(x/5)+1, if (x%5)==0
                n(x/3)+1, if (x%3)==0
                n(x/2)+1, if (x%2)==0
                n(x-1)+1
            }
    n(1) = 0

    bottom-up 방식
    1. d[i-1]과 d[i/2], d[i/3], d[i/5]의 연산횟수 비교
        1-1. -1을 빼는 경우가 더 최소 연산 횟수인 경우 존재(ex. 26)
    2. 5, 3, 2로 나누면서, 배열에 나눈 값(인덱스)에 저장되어있는 
        최솟값으로 i번째 배열 저장
        2-1. 배열에는 i값의 최소 연산수 저장
    3. 배열의 x번째 인덱스 출력
*/

#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    int *op_num = new int(x + 1);
    for (int i=0; i<=x; i++) {
        op_num[i] = 0;
    }
    for (int i=2; i<=x; i++) {
        op_num[i] = op_num[i - 1] + 1; // -1
        if (i % 5 == 0)
            op_num[i] = min(op_num[i], op_num[i / 5] + 1);
        if (i % 3 == 0) 
            op_num[i] = min(op_num[i], op_num[i / 3] + 1);
        if (i % 2 == 0)
            op_num[i] = min(op_num[i], op_num[i / 2] + 1);
    }
    cout << op_num[x] << endl;
}