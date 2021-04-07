/*
EquiLeader
: Find the index S such that the leaders of the sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] are the same.

A non-empty array A consisting of N integers is given.

The leader of this array is the value that occurs in more than half of the elements of A.

An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.

For example, given array A such that:

    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
we can find two equi leaders:

0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
The goal is to count the number of equi leaders.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the number of equi leaders.

For example, given:

    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
the function should return 2, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].

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
    int nRet = 0;

    std::vector<int> copiedVector;
    copiedVector = A;

    int nSize = A.size();

    // 최대 개수를 가지는 요소의 값이 leader 후보이다
    std::sort(copiedVector.begin(), copiedVector.end());
    int nValue = copiedVector[0];
    int nMaxValue = nValue; // 최대의 개수를 갖는 요소의 값
    int nCnt = 1;
    int nMaxCnt = 0; // 최대의 개수를 갖는 요소의 개수
    for (int i = 1; i < nSize; ++i)
    {
        if (nValue < copiedVector[i])
        {

            if (nCnt > nMaxCnt)
            {
                // 최대 값 및 개수 갱신
                nMaxCnt = nCnt;
                nMaxValue = nValue;
            }

            // 기준값 갱신(중요)
            nValue = copiedVector[i];
            nCnt = 1;
        }
        else
        {
            nCnt++;
        }
    }

    if (nCnt > nMaxCnt)
    {
        nMaxValue = nValue;
        nMaxCnt = nCnt;
    }

    //std::cout << "Value: " << nMaxValue << ", Count: " << nMaxCnt << std::endl;

    int nLeftCnt = 0;  // 왼쪽 배열에 있는 leader의 개수
    int nRightCnt = 0; // 오른쪽 배열에 있는 leader의 개수
    int nLeftRef = 0;  // 왼쪽 배열의 기준 개수(기준개수: 부분 배열 전체 길이의 절반 이상)
    int nRightRef = 0; // 오른쪽 배열의 기준 개수
    for (int S = 0; S < nSize - 1; ++S)
    {
        nLeftRef = (S + 1) / 2;
        nRightRef = (nSize - S - 1) / 2;

        if (A[S] == nMaxValue)
        {
            ++nLeftCnt;
        }
        nRightCnt = nMaxCnt - nLeftCnt;

        if ((nLeftCnt > nLeftRef) && (nRightCnt > nRightRef))
        {
            //std::cout << "Left(" << nLeftCnt << ", " << nLeftRef << ") Right(" << nRightCnt << ", " << nRightRef << ")" << std::endl;
            nRet++;
        }
    }

    return nRet;
}

int main()
{
    std::vector<int> input = {4, 3, 4, 4, 4, 2};
    std::cout << solution(input) << std::endl;
    return 0;
}