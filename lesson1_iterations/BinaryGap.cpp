/*
BinaryGap
: Find longest sequence of zeros in binary representation of an integer.

A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
For example, number 9 has binary representation 1001 and contains a binary gap of length 2. 
The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. 
The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.
The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.
For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5.
Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

// you can use includes, for example:
//#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

std::vector<int> makeBinary(int N);

// precondition: 0보다 큰 정수
// postcondition: 가장 긴 Binary Gap의 길이를 리턴. 만약 정수 N이 Binary Gap을 갖고있지 않으면 0을 리턴
int solution(int N)
{
    std::vector<int> vectorBinary;
    std::vector<int>::iterator itr;

    std::stack<int> stackOnes;    // Binary Gap의 기준이되는 1을 스택에서 관리
    std::vector<int> vectorZeros; // Binary Gap에 포함된 0의 집합을 벡터에서 관리

    int nMax = 0;
    int nCandidate = 0;

    vectorBinary = makeBinary(N);
    for (itr = vectorBinary.begin(); itr != vectorBinary.end(); ++itr)
    {
        if (*itr == 1)
        {
            stackOnes.push(1);
            // 스택에 포함된 1의 개수가 2개인 경우에(Gap이라고 판단하는 기준)만 최대 0의 개수를 계산함
            if (stackOnes.size() == 2)
            {
                nCandidate = vectorZeros.size();
                if (nCandidate > nMax)
                {
                    nMax = nCandidate;
                }

                vectorZeros.clear();
                stackOnes.pop();
            }
        }
        else
        {
            // 스택에 1이 하나도 없는 경우에는 0을 카운트하지 않음
            if (!stackOnes.empty())
            {
                vectorZeros.push_back(0);
            }
        }
    }

    return nMax;
}

// precondition: 0보다 큰 정수
// postcondition: 10진수 N을 2진수로 변경한 값을 요소로 갖는 벡터를 반환
std::vector<int> makeBinary(int N)
{
    std::vector<int> vcRet;

    int nQuotient = 0;  // 2로 나누었을때 몫
    int nRemainder = 0; // 2로 나누었을때 나머지

    if (N == 1)
    {
        vcRet.push_back(1);
        return vcRet;
    }

    nRemainder = N % 2;
    vcRet.push_back(nRemainder);
    nQuotient = N / 2;
    if (nQuotient == 1)
    {
        vcRet.push_back(1);
    }

    while (nQuotient > 1)
    {
        nRemainder = nQuotient % 2;
        vcRet.push_back(nRemainder);
        nQuotient = nQuotient / 2;
        if (nQuotient == 1)
        {
            vcRet.push_back(1);
        }
    }

    return vcRet;
}

int main()
{
    std::cout << solution(529) << std::endl;
    std::cout << solution(20) << std::endl;
    std::cout << solution(32) << std::endl;
    std::cout << solution(1041) << std::endl;
}