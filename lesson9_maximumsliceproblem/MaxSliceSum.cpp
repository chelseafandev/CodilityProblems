/*
MaxSliceSum
: Find a maximum sum of a compact subsequence of array elements.

A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. The sum of a slice (P, Q) is the total of A[P] + A[P+1] + ... + A[Q].

Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the maximum sum of any slice of A.

For example, given array A such that:

A[0] = 3  A[1] = 2  A[2] = -6
A[3] = 4  A[4] = 0
the function should return 5 because:

(3, 4) is a slice of A that has sum 4,
(2, 2) is a slice of A that has sum −6,
(0, 1) is a slice of A that has sum 5,
no other slice of A has sum greater than (0, 1).
Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..1,000,000];
each element of array A is an integer within the range [−1,000,000..1,000,000];
the result will be an integer within the range [−2,147,483,648..2,147,483,647].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>

int solution(std::vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    int nSize = A.size();

    // 카데인 알고리즘 적용
    // i번째까지의 부분합의 최대값은 (i-1번째까지의 부분합의 최대값 + A[i]) 와 A[i]중에 더 큰 값이다
    int nMaxSum = A[0];
    int nRet = A[0];
    int nTempSum = 0;
    for (int i = 1; i < nSize; ++i)
    {
        nTempSum = nMaxSum + A[i];
        if (nTempSum > A[i])
        {
            nMaxSum = nTempSum;
        }
        else
        {
            nMaxSum = A[i];
        }

        if (nMaxSum > nRet)
        {
            // 부분합의 최대값을 기억
            nRet = nMaxSum;
        }
    }

    return nRet;
}

int main()
{
    std::vector<int> input = {3, 2, -6, 4, 0};
    std::cout << solution(input) << std::endl;
    return 0;
}