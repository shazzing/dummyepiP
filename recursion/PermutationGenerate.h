//
//  PermutationGenerate.h
//  Recursion
//
//  Created by shashank hegde on 12/19/15.
//  Copyright (c) 2015 shashank hegde. All rights reserved.
//

#ifndef Recursion_PermutationGenerate_h
#define Recursion_PermutationGenerate_h
#include <iostream>

#include <algorithm>
using namespace std;

#include <vector>
void permutationHelper(int i, vector<int>* inp, vector<vector<int>>* result);

vector<vector<int>> permutation(vector<int> input)
{
    vector<vector<int>> result;
    permutationHelper(0, &input, &result);
    return result;
}

void permutationHelper(int i, vector<int>* inp, vector<vector<int>>* result)
{
    if(i == inp->size())
    {
        result->emplace_back(*inp);
        return;
    }
    
    for(int j=i; j<inp->size(); ++j)
    {
        swap((*inp)[i], (*inp)[j]);
        permutationHelper(i+1, inp, result);
        swap((*inp)[i], (*inp)[j]);
    }
    
}
#endif
