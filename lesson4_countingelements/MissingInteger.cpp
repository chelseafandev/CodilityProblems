/*
MissingInteger
: Find the smallest positive integer that does not occur in a given sequence.

This is a demo task.

Write a function:

int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    int nRet = 0;

    // 중복된 요소 제거를 위해 Set활용
    std::set<int> setA;
    std::set<int>::iterator itr;

    // sort를 이용해서 정렬
    std::sort(A.begin(), A.end());

    int nSize = A.size();
    for (int i = 0; i < nSize; ++i)
    {
        setA.insert(A[i]);
    }

    // 정렬된 배열의 가장 큰 요소가 0보다 작거나 같은 경우, 가장 작은 양의 정수는 1
    if (A[nSize - 1] <= 0)
    {
        return 1;
    }
    else
    {
        // 1부터 시작하는 양의 정수중에 빠진 값이 있는지 체크
        int nCount = 1;
        for (itr = setA.begin(); itr != setA.end(); ++itr)
        {
            if (setA.find(nCount) == setA.end())
            {
                break;
            }
            else
            {
                nCount++;
            }
        }
        nRet = nCount;
    }

    return nRet;
}

int main()
{
    std::vector<int> input = {1, 3, 6, 4, 1, 2};
    std::cout << solution(input) << std::endl;
    return 0;
}