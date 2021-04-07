/*
PermCheck
: Check whether array A is a permutation.

A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only once.

For example, array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
is a permutation, but array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

int solution(vector<int> &A);

that, given an array A, returns 1 if array A is a permutation and 0 if it is not.

For example, given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
the function should return 1.

Given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000].

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

    // permutaion(¼ø¿­)ÀÌ¸é 1 ¾Æ´Ï¸é 0À» ¸®ÅÏ
    int nRet = 1;
    int nSize = A.size();

    std::sort(A.begin(), A.end());
    for (int i = 0; i < nSize; ++i)
    {
        if (A[i] != i + 1)
        {
            return 0;
        }
    }

    return nRet;
}

int main()
{
    std::vector<int> input = {4, 1, 3, 2};
    std::cout << solution(input) << std::endl;
    return 0;
}