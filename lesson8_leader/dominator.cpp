/*
Dominator
: Find an index of an array such that its value occurs at more than half of indices in the array.

An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.

For example, consider array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

Write a function

class Solution { public int solution(int[] A); }

that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. The function should return −1 if array A does not have a dominator.

For example, given array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
the function may return 0, 2, 4, 6 or 7, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

// you can use includes, for example:
#include <iostream>
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    // 벡터의 인자 중에 동일한 값이 N의 절반보다 더 많은 경우
    // 값이 dominator이다
    //
    // A가 비어있거나, 싱글 아이템인 경우 예외 처리 필요함

    int nRet = -1;
    int N = A.size();

    if (N == 0)
    {
        return -1;
    }

    if (N == 1)
    {
        return 0;
    }

    std::vector<int> copiedVector = A;
    std::sort(copiedVector.begin(), copiedVector.end());

    int nValue = copiedVector[0];
    int nCount = 1;
    for (int i = 1; i < N; ++i)
    {
        if (nValue == copiedVector[i])
        {
            nCount++;
            if (nCount > N / 2)
            {
                // 기존 배열에서 index 검색
                for (int j = 0; j < N; ++j)
                {
                    if (nValue == A[j])
                    {
                        nRet = j;
                        break;
                    }
                }
                break;
            }
        }
        else
        {
            if (nCount > N / 2)
            {
                // 기존 배열에서 index 검색
                for (int k = 0; k < N; ++k)
                {
                    if (nValue == A[k])
                    {
                        nRet = k;
                        break;
                    }
                }
                break;
            }

            nValue = copiedVector[i];
            nCount = 1;
        }
    }

    return nRet;
}

int main()
{
    std::vector<int> input = {3, 4, 3, 2, 3, -1, 3, 3};
    std::cout << solution(input) << std::endl;
    return 0;
}