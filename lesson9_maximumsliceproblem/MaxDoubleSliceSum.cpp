/*
MaxDoubleSliceSum
: Find the maximal sum of any double slice.

A non-empty array A consisting of N integers is given.

A triplet (X, Y, Z), such that 0 ≤ X < Y < Z < N, is called a double slice.

The sum of double slice (X, Y, Z) is the total of A[X + 1] + A[X + 2] + ... + A[Y − 1] + A[Y + 1] + A[Y + 2] + ... + A[Z − 1].

For example, array A such that:

    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2
contains the following example double slices:

double slice (0, 3, 6), sum is 2 + 6 + 4 + 5 = 17,
double slice (0, 3, 7), sum is 2 + 6 + 4 + 5 − 1 = 16,
double slice (3, 4, 5), sum is 0.
The goal is to find the maximal sum of any double slice.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the maximal sum of any double slice.

For example, given:

    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2
the function should return 17, because no double slice of array A has a sum of greater than 17.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−10,000..10,000].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

// you can use includes, for example:
#include <iostream>
#include <vector>
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    int nRet = 0;

    int nSize = A.size();
    if (nSize == 3)
    {
        return 0;
    }

    std::vector<int> leftSum(nSize);
    std::vector<int> rightSum(nSize);

    // Q1) leftSum과 rightSum의 최대값을 구할때 왜 0과 비교하는지
    // A1)
    for (int i = 1; i < nSize - 1; ++i)
    {
        leftSum[i] = std::max(0, leftSum[i - 1] + A[i]);
    }

    for (int j = nSize - 1; j > 1; --j)
    {
        rightSum[j - 1] = std::max(0, rightSum[j] + A[j - 1]);
    }

    for (int k = 1; k < nSize - 1; ++k)
    {
        nRet = std::max(leftSum[k - 1] + rightSum[k + 1], nRet);
    }

    return nRet;
}

int main()
{
    std::vector<int> input = {3, 2, 6, -1, 4, 5, -1, 2};
    std::cout << solution(input) << std::endl;
    return 0;
}