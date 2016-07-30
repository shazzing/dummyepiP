//
//  countNoScoreCombination.h
//  DSDynamicProgramming
//
//  Created by shashank hegde on 1/3/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef countNoScoreCombination_h
#define countNoScoreCombination_h
#include <vector>

using namespace std;

int countCombination(int k, const vector<int>& arr)
{
    vector<int> combination(k+1, 0);
    combination[0] =1;
    for(const int& score: arr)
    {
        for(int j = score; j<=k; j++)
        {
            combination[j] += combination[j - score];
        }
    }
    return combination[k];
}

int countPermutation(int k, const vector<int>& var)
{
    vector<int> permutation(k+1, 0);
    permutation[0] = 1;
    for(int i=0; i<k; i++)
    {
        for(const int& score: var)
        {
            if(i>=score)
            {
                permutation[i] += permutation[i-score];
            }
        }
    }
    return permutation[k];
}

#endif /* countNoScoreCombination_h */
