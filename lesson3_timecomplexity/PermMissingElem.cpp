/*
PermMissingElem
: Find the missing element in a given permutation.

An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], 
which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

int solution(vector<int> &A);
that, given an array A, returns the value of the missing element.

For example, given array A such that:

  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].

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
    int nSize = A.size();
    int N = A.size() + 1;

    // (주의) INPUT은 배열 A이고, 비교대상은 [1,2, ..., (N+1)]
    sort(A.begin(), A.end());
    for (int i = 0; i < nSize; ++i)
    {
        if (A[i] != i + 1)
        {
            return i + 1;
        }
    }

    return N;
}

int main()
{
    std::vector<int> input;
    input.push_back(2);
    input.push_back(3);
    input.push_back(1);
    input.push_back(5);

    std::cout << solution(input) << std::endl;

    return 0;
}