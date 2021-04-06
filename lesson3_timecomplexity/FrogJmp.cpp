/*
FrogJmp
: Count minimal number of jumps from position X to Y.

A small frog wants to get to the other side of the road. 
The frog is currently located at position X and wants to get to a position greater than or equal to Y. 
The small frog always jumps a fixed distance, D.

Count the minimal number of jumps that the small frog must perform to reach its target.

Write a function:

int solution(int X, int Y, int D);
that, given three integers X, Y and D, returns the minimal number of jumps from position X to a position 
equal to or greater than Y.

For example, given:

  X = 10
  Y = 85
  D = 30
the function should return 3, because the frog will be positioned as follows:

after the first jump, at position 10 + 30 = 40
after the second jump, at position 10 + 30 + 30 = 70
after the third jump, at position 10 + 30 + 30 + 30 = 100
Write an efficient algorithm for the following assumptions:

X, Y and D are integers within the range [1..1,000,000,000];
X ≤ Y.

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
// you can use includes, for example:
// #include <algorithm>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D)
{
    // write your code in C++14 (g++ 6.2.0)

    int nRet = 0;

    // X: 개구리의 현재 위치
    // Y: 도달하고자 하는 위치
    // D: 한번 점프로 이동할 수 있는 거리
    int nDiff = Y - X;

    int nQuotient = nDiff / D;
    int nRemainder = nDiff % D;

    // 시작점과 도달점이 같은 경우
    if (nDiff == 0)
    {
        return 0;
    }

    // 한 번의 점프로 이동 가능
    if (nQuotient == 0)
    {
        return 1;
    }

    if (nRemainder != 0)
    {
        nRet = nQuotient + 1;
    }
    else
    {
        nRet = nQuotient;
    }

    return nRet;
}

int main() 
{
    std::cout << solution(10, 85, 30) << std::endl;
    return 0;
}