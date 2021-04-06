/*
CyclicRotation
: Rotate an array to the right by a given number of steps.

An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, 
and the last element of the array is moved to the first place. 
For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] 
(elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Write a function:

vector<int> solution(vector<int> &A, int K);
that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given

    A = [3, 8, 9, 7, 6]
    K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
For another example, given

    A = [0, 0, 0]
    K = 1
the function should return [0, 0, 0]

Given

    A = [1, 2, 3, 4]
    K = 4
the function should return [1, 2, 3, 4]

Assume that:

N and K are integers within the range [0..100];
each element of array A is an integer within the range [−1,000..1,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;a

std::vector<int> solution(std::vector<int> &A, int K) {
	// write your code in C++14 (g++ 6.2.0)
	std::vector<int> vcRet;

	int nCount = 0;
	int nSizeA = A.size();

	// 입력이 빈 벡터인 경우 처리
	if (nSizeA == 0)
	{
		return vcRet;
	}

	// (반복횟수 K가 입력값 벡터 A의 사이즈보다 큰 경우) 인덱스값이 음수가 나오는 것을 방지
	if (K > nSizeA)
	{
		nCount = K % nSizeA;
	}
	else
	{
		nCount = K;
	}

	int nIndex = 0;
	for (int i = 0; i < nCount; ++i)
	{
		nIndex = nSizeA - (nCount - i);
		vcRet.push_back(A[nIndex]);
	}

	for (int j = 0; j < nSizeA - nCount; ++j)
	{
		vcRet.push_back(A[j]);
	}

	return vcRet;
}

int main()
{
    // 3, 8, 9, 7, 6
    std::vector<int> input;
    input.push_back(3);
    input.push_back(8);
    input.push_back(9);
    input.push_back(7);
    input.push_back(6);

    std::vector<int>::iterator itr;
    std::vector<int> output = solution(input, 3);
    for(itr = output.begin(); itr != output.end(); itr++){
        std::cout << *itr << std::endl;
    }

    return 0;
}