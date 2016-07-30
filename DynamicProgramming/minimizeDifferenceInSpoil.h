//
//  minimizeDifferenceInSpoil.h
//  DSDynamicProgramming
//
//  Created by shashank hegde on 1/6/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef minimizeDifferenceInSpoil_h
#define minimizeDifferenceInSpoil_h
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;


int minimizeDifference(const vector<int>& a)
{
    int sum = std::accumulate(a.begin(), a.end(), 0);
    unordered_set<int> is_OK;
    is_OK.emplace(0);
    for(const int& item:a)
    {
        for(int v=sum/2; v>=item; v--)
        {
            if(is_OK.find(v-item) != is_OK.cend()){
                is_OK.emplace(v);
            }
        }
    }

    // find the first i from miffle is_ok[i] == true
    for(int i=sum/2; i >0; i--)
    {
        if(is_OK.find(i) != is_OK.cend())
        {
            return (sum-i)-i;
        }
    }
    return sum; //one theif takes all 
}

#endif /* minimizeDifferenceInSpoil_h */
