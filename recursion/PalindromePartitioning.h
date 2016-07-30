//
//  PalindromePartitioning.h
//  Recursion
//
//  Created by shashank hegde on 12/20/15.
//  Copyright (c) 2015 shashank hegde. All rights reserved.
//

#ifndef Recursion_PalindromePartitioning_h
#define Recursion_PalindromePartitioning_h
#include <vector>
#include <string>
using namespace std;
bool isPalindrome(const string& src)
{
    for(size_t i=0, j=src.size()-1; i < j; i++, j--)
    {
        if(src[i] != src[j])
            return false;
    }
    return true;
}
void palindromDecompositionHelper(const string& src, int offset,
                                  vector<string>* palindromDecomp, vector<vector<string>>* result)
{
    if(offset == src.size())
    {
        result->emplace_back(*palindromDecomp);
        return;
    }
    
    for(int i=offset+1; i< src.size(); i++)
    {
        string subset = src.substr(offset, i-offset);
        if(isPalindrome(subset))
        {
            palindromDecomp->emplace_back(subset);
            palindromDecompositionHelper(src, i, palindromDecomp, result);
            palindromDecomp->pop_back();
        }
    }
}
vector<vector<string>> palindromeDecomposition(const string src )
{
    vector<vector<string>> result;
    vector<string> palindromDecomp;
    palindromDecompositionHelper(src, 0, &palindromDecomp, &result);
    return result;
}

#endif
