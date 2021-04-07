/*
StoneWall
: Cover "Manhattan skyline" using the minimum number of rectangles.

You are going to build a stone wall. The wall should be straight and N meters long, and its thickness should be constant; however, it should have different heights in different places. The height of the wall is specified by an array H of N positive integers. H[I] is the height of the wall from I to I+1 meters to the right of its left end. In particular, H[0] is the height of the wall's left end and H[N−1] is the height of the wall's right end.

The wall should be built of cuboid stone blocks (that is, all sides of such blocks are rectangular). Your task is to compute the minimum number of blocks needed to build the wall.

Write a function:

int solution(vector<int> &H);

that, given an array H of N positive integers specifying the height of the wall, returns the minimum number of blocks needed to build it.

For example, given array H containing N = 9 integers:

  H[0] = 8    H[1] = 8    H[2] = 5
  H[3] = 7    H[4] = 9    H[5] = 8
  H[6] = 7    H[7] = 4    H[8] = 8
the function should return 7. The figure shows one possible arrangement of seven blocks.



Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array H is an integer within the range [1..1,000,000,000].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &H)
{
  // write your code in C++14 (g++ 6.2.0)

  int nMinBlockCnt = 0;

  // Height값을 Stack에 push하면서 최소 블록 개수(nMinBlockCnt)를 계산한다
  //
  // 1) Height의 값이 이전의 값(Stack의 top값)과 동일한 경우 처리
  //      - 최소 블록의 개수에 변함이 없음
  // 2) Height의 값이 이전의 값(Stack의 top값)보다 큰 경우 처리
  //      - Stack에 push후 최소 블록의 개수 +1
  // 3) Height의 값이 이전의 값(Stack의 top값)보다 작은 경우 처리

  std::stack<int> heightStack;

  int nSize = H.size();
  for (int i = 0; i < nSize; ++i)
  {
    if (heightStack.empty())
    {
      heightStack.push(H[i]);
      nMinBlockCnt++;
    }
    else
    {
      if (heightStack.top() > H[i])
      {
        heightStack.pop();

        while (!heightStack.empty() && heightStack.top() > H[i])
        {
          heightStack.pop();
        }

        if (heightStack.empty() || heightStack.top() < H[i])
        {
          heightStack.push(H[i]);
          nMinBlockCnt++;
        }
      }
      else if (heightStack.top() < H[i])
      {
        heightStack.push(H[i]);
        nMinBlockCnt++;
      }
    }
  }

  return nMinBlockCnt;
}

int main()
{
  std::vector<int> input = {8, 8, 5, 7, 9, 8, 7, 4, 8};
  std::cout << solution(input) << std::endl;
  return 0;
}