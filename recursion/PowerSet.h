//
//  PowerSet.h
//  Recursion
//
//  Created by shashank hegde on 12/19/15.
//  Copyright (c) 2015 shashank hegde. All rights reserved.
//

#ifndef Recursion_PowerSet_h
#define Recursion_PowerSet_h
#include <vector>

using namespace std;

void powerSetHelper(const vector<int>& input, int toBeSelected, vector<int>* selectedSoFar, vector<vector<int>>* result)
{
    if(toBeSelected == input.size())
    {
        result->emplace_back(*selectedSoFar);
        return;
    }
    selectedSoFar->emplace_back(input[toBeSelected]);
    powerSetHelper(input, toBeSelected+1, selectedSoFar, result);
    selectedSoFar->pop_back();
    // get the elements without tobeSelected element this time.
    powerSetHelper(input, toBeSelected +1, selectedSoFar, result);
}


vector<vector<int>> powerSet(const vector<int>& inp)
{
    vector<vector<int>> powerSetRes;
    vector<int> selectedSoFar;
    powerSetHelper(inp, 0, &selectedSoFar, &powerSetRes);
    return powerSetRes;
}

#endif
