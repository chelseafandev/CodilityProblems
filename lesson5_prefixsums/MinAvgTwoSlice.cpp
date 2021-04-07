/*
MinAvgTwoSlice
: Find the minimal average of any slice containing at least two elements.

A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P < Q < N, is called a slice of array A (notice that the slice contains at least two elements). The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).

For example, array A such that:

    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8
contains the following example slices:

slice (1, 2), whose average is (2 + 2) / 2 = 2;
slice (3, 4), whose average is (5 + 1) / 2 = 3;
slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.
The goal is to find the starting position of a slice whose average is minimal.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the starting position of the slice with the minimal average. If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.

For example, given array A such that:

    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−10,000..10,000].

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    // slice가 2개, 3개일때의 평균값만 비교하면 되는 이유
    //
    // a <= b 인 경우, 평균은 a보다는 크다
    // a+b <= c+d 인 경우, 평균은 (a+b)보다는 크다
    //
    // 이를 통해 slice가 4개인 경우를 살펴보면
    // a+b의 평균과 c+d의 평균 중에 더 작은 값보다는 a+b+c+d의 평균이 크기때문에
    // (즉, slice가 4개인 평균의 최소값은 slice가 2개인 평균의 최소값 보다 항상 크다)
    // slice가 4개인 평균은 구할 필요가 없어진다
    //
    // slice가 5개인 경우도 slice가 2개인 그룹과 slice가 3개인 그룹 둘로 나눌 수 있다.
    // 마찬가지로 slice 5개의 평균은 두 그룹 중 평균이 더 작은 그룹보다는 크기때문에
    // slice가 2개인 경우와 3개인 경우의 최소 평균을 구한다면 slice가 5개인 경우는 알 필요가 없어진다

    int minAvgIdx = 0;
    double minAvgValue = (A[0] + A[1]) / 2.0;

    double tmpAvg = 0;
    for (int i = 2; i < A.size(); ++i)
    {
        tmpAvg = (A[i - 2] + A[i - 1] + A[i]) / 3.0;
        if (minAvgValue > tmpAvg)
        {
            minAvgValue = tmpAvg;
            minAvgIdx = i - 2;
        }

        tmpAvg = (A[i - 1] + A[i]) / 2.0;
        if (minAvgValue > tmpAvg)
        {
            minAvgValue = tmpAvg;
            minAvgIdx = i - 1;
        }
    }

    return minAvgIdx;
}

int main()
{
    std::vector<int> input = {4, 2, 2, 5, 1, 5, 8};
    std::cout << solution(input) << std::endl;
    return 0;
}