/*
FrogRiverOne
:Find the earliest time when a frog can jump to the other side of a river.

A small frog wants to get to the other side of a river. The frog is initially located on one bank of the river (position 0) 
and wants to get to the opposite bank (position X+1). Leaves fall from a tree onto the surface of the river.

You are given an array A consisting of N integers representing the falling leaves. 
A[K] represents the position where one leaf falls at time K, measured in seconds.

The goal is to find the earliest time when the frog can jump to the other side of the river. 
The frog can cross only when leaves appear at every position across the river from 1 to X (that is, we want to find the earliest moment when all the positions from 1 to X are covered by leaves). You may assume that the speed of the current in the river is negligibly small, i.e. the leaves do not change their positions once they fall in the river.

For example, you are given integer X = 5 and array A such that:

  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4
In second 6, a leaf falls into position 5. This is the earliest time when leaves appear in every position across the river.

Write a function:

int solution(int X, vector<int> &A);

that, given a non-empty array A consisting of N integers and integer X, returns the earliest time 
when the frog can jump to the other side of the river.

If the frog is never able to jump to the other side of the river, the function should return −1.

For example, given X = 5 and array A such that:

  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4
the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

N and X are integers within the range [1..100,000];
each element of array A is an integer within the range [1..X].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, std::vector<int> &A)
{
  // write your code in C++14 (g++ 6.2.0)

  // The frog can cross only when leaves appear at every position across the river from 1 to X.
  // (that is, we want to find the earliest moment when all the positions from 1 to X are covered by leaves)
  // 개구리가 이동하려는 모든 위치에 나뭇잎이 존재해야함

  // the leaves do not change their positions once they fall in the river.
  // 강물에 한번 떨어진 나뭇잎의 위치는 변하지 않는다고 가정

  int nRet = -1;
  int nSize = A.size();

  int nCount = 0;
  bool *bIsChecked = new bool[X + 1]; // 1부터 X까지의 경로에 나뭇잎에 떨어져있는지 여부를 체크
  for (int i = 0; i < X + 1; ++i)
  {
    bIsChecked[i] = false;
  }

  for (int j = 0; j < nSize; ++j)
  {

    if (!bIsChecked[A[j]])
    {
      nCount++;
      bIsChecked[A[j]] = true;

      // 도달하고자 하는 X만큼 나뭇잎이 떨어졌다면 반복문을 빠져나옴
      if (nCount == X)
      {
        nRet = j;
        break;
      }
    }
  }

  delete[] bIsChecked;

  return nRet;
}

int main()
{
  std::vector<int> input = {1, 3, 1, 4, 2, 3, 5, 4};
  std::cout << solution(5, input) << std::endl;
  return 0;
}