/*
Nesting
: Determine whether a given string of parentheses (single type) is properly nested.

A string S consisting of N characters is called properly nested if:

S is empty;
S has the form "(U)" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, string "(()(())())" is properly nested but string "())" isn't.

Write a function:

int solution(string &S);

that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.

For example, given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..1,000,000];
string S consists only of the characters "(" and/or ")".

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::string &S)
{
    // write your code in C++14 (g++ 6.2.0)
    std::stack<char> parenStack;

    int nSize = S.length();
    if (nSize == 0)
    {
        return 1;
    }

    for (int i = 0; i < nSize; ++i)
    {
        if (S[i] == '(')
        {
            parenStack.push(S[i]);
        }
        else
        {
            if (parenStack.top() == '(')
            {
                parenStack.pop();
            }
            else
            {
                return 0;
            }
        }
    }

    if (parenStack.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    std::string S = "(()(())())";
    std::cout << solution(S) << std::endl;
    return 0;
}