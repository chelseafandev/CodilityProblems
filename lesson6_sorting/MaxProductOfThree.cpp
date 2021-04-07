/*
MaxProductOfThree
: Maximize A[P] * A[Q] * A[R] for any triplet (P, Q, R).

A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
contains the following example triplets:

(0, 1, 2), product is −3 * 1 * 2 = −6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60
Your goal is to find the maximal product of any triplet.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A, returns the value of the maximal product of any triplet.

For example, given array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
the function should return 60, as the product of triplet (2, 4, 5) is maximal.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−1,000..1,000].

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

  // sort를 통해 정렬하고
  // 세 수의 곱이 최대가 될 수있는 경우의 수 체크
  //
  // 1) 음수 X 음수 X 양수 = A[0] * A[1] * A[N-1]
  // 2) 양수 X 양수 X 양수 = A[N-3] * A[N-2] * A[N-1]
  //
  int nRet = 0;
  int nSize = A.size();

  std::sort(A.begin(), A.end());

  int nLeftTriplet = A[0] * A[1] * A[nSize - 1];
  int nRightTriplet = A[nSize - 3] * A[nSize - 2] * A[nSize - 1];

  if (nLeftTriplet < 0)
  {
    nRet = nRightTriplet;
  }
  else
  {
    if (nLeftTriplet < nRightTriplet)
    {
      nRet = nRightTriplet;
    }
    else
    {
      nRet = nLeftTriplet;
    }
  }

  return nRet;
}

int main()
{
  std::vector<int> input = {-3, 1, 2, -2, 5, 6};
  std::cout << solution(input) << std::endl;
  return 0;
}