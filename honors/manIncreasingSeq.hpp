//
//  manIncreasingSeq.hpp
//  epi
//
//  Created by shashank hegde on 8/5/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef manIncreasingSeq_h
#define manIncreasingSeq_h
#include <vector>
#include <utility>

using namespace std;

pair<int, int> maxIncreasingSeqLen(const vector<int>& A){
    vector<int> increasingSeqLens(A.size(), 1);
    pair<int, int> maxIncrLenIndex = {1,0};
    for(size_t i=1; i<A.size(); i++){
        if(A[i] > A[i-1]){
            increasingSeqLens[i] = increasingSeqLens[i-1] + 1;
            if(increasingSeqLens[i] > maxIncrLenIndex.first){
                maxIncrLenIndex = make_pair(increasingSeqLens[i], i);
                
            }
        }
    }
    return make_pair(maxIncrLenIndex.second - maxIncrLenIndex.first + 1, maxIncrLenIndex.second);
}

#endif /* manIncreasingSeq_h */
