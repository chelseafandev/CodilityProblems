/*
TapeEquilibrium
: Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.

A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: 
A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7 
P = 2, difference = |4 − 9| = 5 
P = 3, difference = |6 − 7| = 1 
P = 4, difference = |10 − 3| = 7 
Write a function:

int solution(vector<int> &A);
that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

For example, given:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <vector>
#include <complex> // abs

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    std::vector<int> vcPartialSum;

    // [3, 1, 2, 4, 3]
    // 전체 합: 13
    // P가 1인 경우, |13 - 3 - 3| = 7
    // P가 2인 경우, |13 - (3+1) - (3+1)| = 5
    // P가 3인 경우, |13 - (3+1+2) - (3+1+2)| = 1
    // P가 4인 경우, |13 - (3+1+2+4) - (3+1+2+4)| = 7
    // ...
    // P가 N-1인 경우, |전체합 - (인덱스0부터 N-2까지의 합)*2|
    int nTmp = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        nTmp += A[i];
        vcPartialSum.push_back(nTmp * 2);
    }

    int nSum = nTmp + A[N - 1];
    int nDiff = 0;
    int nMin = -1;
    for (int j = 0; j < N - 1; ++j)
    {
        nDiff = abs(nSum - vcPartialSum[j]);
        if (nMin == -1)
        {
            nMin = nDiff;
        }
        else
        {
            if (nMin > nDiff)
            {
                nMin = nDiff;
            }
        }
    }

    return nMin;
}

int main()
{
    std::vector<int> input;
    input.push_back(3);
    input.push_back(1);
    input.push_back(2);
    input.push_back(4);
    input.push_back(3);

    std::cout << solution(input) << std::endl;

    return 0;
}