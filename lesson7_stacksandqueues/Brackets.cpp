/*
Brackets
: Determine whether a given string of parentheses (multiple types) is properly nested.

A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:

S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

int solution(string &S);

that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..200,000];
string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool CheckCharacter(std::stack<char> &stk, const char szChar);

int solution(std::string &S)
{
    // write your code in C++14 (g++ 6.2.0)

    std::stack<char> specCharStack;

    int nSize = S.length();

    if (nSize == 0)
    {
        return 1;
    }

    for (int i = 0; i < nSize; ++i)
    {
        if ((S[i] == '(') || (S[i] == '{') || (S[i] == '['))
        {
            specCharStack.push(S[i]);
        }
        else
        {
            if (specCharStack.empty())
            {
                return 0;
            }
            else
            {
                if (!CheckCharacter(specCharStack, S[i]))
                {
                    return 0;
                }
            }
        }
    }

    if (specCharStack.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool CheckCharacter(std::stack<char> &stk, const char szChar)
{
    bool bRet = false;

    switch (szChar)
    {
    case ')':
        if (stk.top() == '(')
        {
            bRet = true;
        }
        break;
    case '}':
        if (stk.top() == '{')
        {
            bRet = true;
        }
        break;
    case ']':
        if (stk.top() == '[')
        {
            bRet = true;
        }
        break;
    }

    stk.pop();
    return bRet;
}

int main()
{
    std::string S = "{[()()]}";
    std::cout << solution(S) << std::endl;
    return 0;
}