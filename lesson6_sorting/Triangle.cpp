/*
Triangle
: Determine whether a triangle can be built from a given set of edges.

An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:

A[P] + A[Q] > A[R],
A[Q] + A[R] > A[P],
A[R] + A[P] > A[Q].
For example, consider array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20
Triplet (0, 2, 4) is triangular.

Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.

For example, given array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20
the function should return 1, as explained above. Given array A such that:

  A[0] = 10    A[1] = 50    A[2] = 5
  A[3] = 1
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
// you can use includes, for example:
#include <iostream>
#include <vector>
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool isTriangular(int P, int Q, int R);

int solution(std::vector<int> &A)
{
  // write your code in C++14 (g++ 6.2.0)
  int nRet = 0;

  // P < Q < R
  //
  // A[P] > A[R] - A[Q]
  // A[P] > A[Q] - A[R]
  //
  // A[Q] > A[R] - A[P]
  // A[Q] > A[P] - A[R]
  //
  // A[R] > A[Q] - A[P]
  // A[R] > A[P] - A[Q]

  // 완전 탐색으로 가능한가?
  // O(N^3)으로 최대 N값 100,000을 만족시키지 못함
  std::sort(A.begin(), A.end());

  bool bResult = false;

  for (int i = 0; i < A.size(); ++i)
  {
    for (int j = i + 1; j < A.size(); ++j)
    {
      for (int k = j + 1; k < A.size(); ++k)
      {
        bResult = isTriangular(A[i], A[j], A[k]);
        if (!bResult)
        {
          //std::cout << "(" << A[i] << ", " << A[j] << ", " << A[k] << ")" << std::endl;
          break;
        }
        else
        {
          return 1;
        }
      }

      if (!bResult)
      {
        break;
      }
    }
  }

  return nRet;
}

bool isTriangular(int P, int Q, int R)
{
  bool bRet = false;

  if ((P > (Q - R)) && (P > (R - Q)))
  {
    if ((Q > (P - R)) && (Q > (R - P)))
    {
      if ((R > (P - Q)) && (R > (Q - P)))
      {
        bRet = true;
      }
    }
  }

  return bRet;
}

int main()
{
  std::vector<int> input = {10, 2, 5, 1, 8, 20};
  std::cout << solution(input) << std::endl;
  return 0;
}