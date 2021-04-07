/*
CountFactors
: Count factors of given number n.

A positive integer D is a factor of a positive integer N if there exists an integer M such that N = D * M.

For example, 6 is a factor of 24, because M = 4 satisfies the above condition (24 = 6 * 4).

Write a function:

int solution(int N);

that, given a positive integer N, returns the number of its factors.

For example, given N = 24, the function should return 8, because 24 has 8 factors, namely 1, 2, 3, 4, 6, 8, 12, 24. There are no other factors of 24.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N)
{
    // write your code in C++14 (g++ 6.2.0)
    bool bFlag = false;

    // sqrt(N)까지만 구하면 전체 factor요소를 알 수 있음
    int sqrtN = sqrt(N);
    if (sqrtN * sqrtN == N)
    {
        bFlag = true;
    }

    int nTwice = 0;
    int nOnce = 0;
    for (int i = 1; i <= sqrtN; ++i)
    {
        if (N % i == 0)
        {
            if (i == sqrtN && bFlag == true)
            {
                nOnce++;
            }
            else
            {
                nTwice++;
            }
        }
    }

    return nTwice * 2 + nOnce;
}

int main()
{
    std::cout << solution(24) << std::endl;
    return 0;
}