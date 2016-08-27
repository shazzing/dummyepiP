//
//  powerSet.hpp
//  epi
//
//  Created by shashank hegde on 8/24/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef powerSet_h
#define powerSet_h
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> powerSetHelper(const vector<int>& A, int index){
    vector<vector<int>> allSubSets;
    if(index == A.size()){
        allSubSets.emplace_back(vector<int>()); //empty set
    }
    else{
        allSubSets = powerSetHelper(A, index+1);
        int item = A[index];
        vector<vector<int>> moreSubSets;
        for(vector<int> subset: allSubSets){
            vector<int> currSet;
            copy(subset.begin(), subset.end(), back_inserter(currSet));
            currSet.emplace_back(item);
            moreSubSets.emplace_back(currSet);
        }
        copy(moreSubSets.begin(), moreSubSets.end(), back_inserter(allSubSets));
    }
    return allSubSets;
}

vector<vector<int>> getPowerSet(const vector<int>& A){
    return powerSetHelper(A, 0);
}



#endif /* powerSet_h */
