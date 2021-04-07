/*
MaxCounters
: Calculate the values of counters after applying all alternating operations: increase counter by 1; 
set value of all counters to current maximum.

You are given N counters, initially set to 0, and you have two possible operations on them:

increase(X) − counter X is increased by 1,
max counter − all counters are set to the maximum value of any counter.
A non-empty array A of M integers is given. This array represents consecutive operations:

if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
if A[K] = N + 1 then operation K is max counter.
For example, given integer N = 5 and array A such that:

    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4
the values of the counters after each consecutive operation will be:

    (0, 0, 1, 0, 0)
    (0, 0, 1, 1, 0)
    (0, 0, 1, 2, 0)
    (2, 2, 2, 2, 2)
    (3, 2, 2, 2, 2)
    (3, 2, 2, 3, 2)
    (3, 2, 2, 4, 2)
The goal is to calculate the value of every counter after all operations.

Write a function:

vector<int> solution(int N, vector<int> &A);

that, given an integer N and a non-empty array A consisting of M integers, returns a sequence of integers representing the values of the counters.

Result array should be returned as a vector of integers.

For example, given:

    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4
the function should return [3, 2, 2, 4, 2], as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..100,000];
each element of array A is an integer within the range [1..N + 1].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
#include <iostream>
// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <cstring> // memset

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
std::vector<int> solution(int N, std::vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    std::vector<int> vcRet;

    int *pCounter = new int[N];
    memset(pCounter, 0, N * sizeof(int));

    int nSize = A.size();
    int nIndex = 0;
    int nMax = 0;      // vcRet의 요소 중 가장 큰 값
    int nFinalMax = 0; // 마지막 max counter 연산 시의 counter값
    for (int i = 0; i < nSize; ++i)
    {
        // N+1인 경우 어떻게 효율적으로 처리할 것인가
        if (A[i] > N)
        {
            nIndex = i + 1;
            if (nMax != 0)
            {
                nFinalMax += nMax;
                memset(pCounter, 0, N * sizeof(int)); // 정수값을 갖는 배열 초기화는 memset으로 진행
                nMax = 0;
            }
        }
        else
        {
            pCounter[A[i] - 1]++;
            if (nMax < pCounter[A[i] - 1])
            {
                nMax = pCounter[A[i] - 1];
            }
        }
    }

    // 마지막 max counter 연산으로 결정되는 nFinalMax값을 초기값으로 하는 N개의 요소를 갖는 벡터 할당 후
    // 남은 increase 연산을 진행함
    // 남아있는 increase 연산이 없는 경우는 벡터 할당 후 바로 리턴함
    vcRet.assign(N, nFinalMax);
    if (nIndex < nSize)
    {
        for (int j = nIndex; j < nSize; ++j)
        {
            vcRet[A[j] - 1]++;
        }
    }

    delete[] pCounter;
    return vcRet;
}

int main()
{
    std::vector<int> input = {3, 4, 4, 6, 1, 4, 4};
    std::vector<int> output;
    std::vector<int>::iterator itr;

    output = solution(5, input);

    for (itr = output.begin(); itr != output.end(); itr++)
    {
        std::cout << *itr << std::endl;
    }

    return 0;
}