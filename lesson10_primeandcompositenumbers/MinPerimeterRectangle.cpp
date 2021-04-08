/*
MinPerimeterRectangle
: Find the minimal perimeter of any rectangle whose area equals N.

An integer N is given, representing the area of some rectangle.

The area of a rectangle whose sides are of length A and B is A * B, and the perimeter is 2 * (A + B).

The goal is to find the minimal perimeter of any rectangle whose area equals N. The sides of this rectangle should be only integers.

For example, given integer N = 30, rectangles of area 30 are:

(1, 30), with a perimeter of 62,
(2, 15), with a perimeter of 34,
(3, 10), with a perimeter of 26,
(5, 6), with a perimeter of 22.
Write a function:

int solution(int N);

that, given an integer N, returns the minimal perimeter of any rectangle whose area is exactly equal to N.

For example, given an integer N = 30, the function should return 22, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..1,000,000,000].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
#include <iostream>
#include <cmath>

int solution(int N)
{
    if (N == 1)
    {
        return 2 * (1 + 1);
    }

    // write your code in C++14 (g++ 6.2.0)
    int nMin = 0;
    int nCandidate = 0;

    for (int i = 1; i <= sqrt(N); i++)
    {
        if ((N % i) == 0)
        {
            nCandidate = 2 * (i + (N / i));
            if (nMin == 0)
            {
                nMin = nCandidate;
            }
            else if (nMin > nCandidate)
            {
                nMin = nCandidate;
            }
        }
    }

    return nMin;
}

int main()
{
    std::cout << solution(1) << std::endl;
    std::cout << solution(1000000000) << std::endl;
    return 0;
}