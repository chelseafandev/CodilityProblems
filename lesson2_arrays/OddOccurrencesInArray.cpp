/*
OddOccurrencesInArray
: Find value that occurs in odd number of elements.

A non-empty array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.

For example, in array A such that:

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
the elements at indexes 0 and 2 have value 9,
the elements at indexes 1 and 3 have value 3,
the elements at indexes 4 and 6 have value 9,
the element at index 5 has value 7 and is unpaired.
Write a function:

int solution(vector<int> &A);
that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.

For example, given array A such that:

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
the function should return 7, as explained in the example above.

Write an efficient algorithm for the following assumptions:

N is an odd integer within the range [1..1,000,000];
each element of array A is an integer within the range [1..1,000,000,000];
all but one of the values in A occur an even number of times.

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A)
{
	/*
	// Map을 활용한 방법. 시간복잡도는 sort를 사용했을때와 동일하게 O(n*log(n)) 이지만, 마지막 검증 Input에 대해서 시간 초과 오류가 발생함
	
	int nRet = 0;

	//std::vector<int>::iterator itrVector;
	int nVectorSize = A.size();
	std::map<int, int>::iterator itrMap;

	// <홀수값, 개수>
	std::map<int, int> mapPair;
	for (itrVector = A.begin(); itrVector != A.end(); ++itrVector)
	{
		// map의 find함수의 시간 복잡도는 O(log n)
		itrMap = mapPair.find(*itrVector);
		if (itrMap == mapPair.end())
		{
			// 중복된 키가 없는 경우
			mapPair.insert(std::make_pair(*itrVector, 1));
		}
		else
		{
			itrMap->second += 1;
		}
	}

	for (itrMap = mapPair.begin(); itrMap != mapPair.end(); ++itrMap)
	{
		// 카운팅 개수가 짝수가 아닌 경우
		if ((itrMap->second % 2) != 0)
		{
			nRet = itrMap->first;
			break;
		}
	}

	return nRet;
	*/

	// write your code in C++14 (g++ 6.2.0)
	int nRet = 0;

	// sort를 통해 크기순으로 정렬(default: 오름차순)
	// c++ STL sort함수는 O(n*log(n))의 시간복잡도를 갖는다
	sort(A.begin(), A.end());

	for (int i = 0; i < A.size(); i = i + 2)
	{
		// 홀수번째 인덱스를 기준으로
		// 그 다음번 인덱스의 값과 비교하여
		// 일치하면 Pair라고 판단할 수 있음
		if (A[i] != A[i + 1])
		{
			nRet = A[i];
			break;
		}
	}

	return nRet;
}

int main()
{
	std::vector<int> input;
	input.push_back(9);
	input.push_back(3);
	input.push_back(9);
	input.push_back(3);
	input.push_back(9);
	input.push_back(7);
	input.push_back(9);

	std::cout << solution(input) << std::endl;
	return 0;
}