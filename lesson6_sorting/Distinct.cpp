/*
Distinct
: Compute number of distinct values in an array.

Write a function

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the number of distinct values in array A.

For example, given array A consisting of six elements such that:

 A[0] = 2    A[1] = 1    A[2] = 1
 A[3] = 2    A[4] = 3    A[5] = 1
the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <vector>
#include <set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    int nRet = 0;

    // 중복을 허용하지 않는 컨테이너인 Set 활용
    std::set<int> setDistinct;

    int nSize = A.size();
    for (int i = 0; i < nSize; ++i)
    {
        setDistinct.insert(A[i]);
    }

    nRet = setDistinct.size();

    return nRet;
}

int main()
{
    std::vector<int> input = {2, 1, 1, 2, 3, 1};
    std::cout << solution(input) << std::endl;
    return 0;
}