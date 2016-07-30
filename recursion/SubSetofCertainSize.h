//
//  SubSetofCertainSize.h
//  Recursion
//
//  Created by shashank hegde on 12/19/15.
//  Copyright (c) 2015 shashank hegde. All rights reserved.
//

#ifndef Recursion_SubSetofCertainSize_h
#define Recursion_SubSetofCertainSize_h
#include <vector>
using namespace std;

void subsetOfCertainSizeHelper(int n, int k , int offset, vector<int>* partialSubSet, vector<vector<int>>* result)
{
    if(partialSubSet->size() == k)
    {
        result->emplace_back(*partialSubSet);
        return;
    }
    size_t kNumRemaining = k - partialSubSet->size();
    for(size_t i=offset;i<=n && kNumRemaining < n-i; ++i)
    {
        partialSubSet->emplace_back(i);
        subsetOfCertainSizeHelper(n, k, i+1, partialSubSet, result );
        partialSubSet->pop_back();
    }
}
vector<vector<int>> subsetOfCertainSize(int n, int k)
{
    vector<vector<int>> result;
    vector<int> partialSubSet;
    subsetOfCertainSizeHelper(n, k, 0, &partialSubSet, &result);
    return result;
}

#endif
