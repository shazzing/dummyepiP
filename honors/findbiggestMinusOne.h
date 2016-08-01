//
//  findbiggestMinusOne.h
//  epi-honours
//
//  Created by shashank hegde on 5/24/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef findbiggestMinusOne_h
#define findbiggestMinusOne_h
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
using namespace std;

int maxProductMinusOne(const vector<int>& A ){
    vector<int> L, R(A.size());
    partial_sum(A.cbegin(), A.cend(), back_inserter(L), multiplies<int>());
    partial_sum(A.crbegin(), A.crend(), R.rbegin(), multiplies<int>());
    
    int maxProduct = numeric_limits<int>::min();
    for(int i=0; i<A.size(); i++){
        int forward = i > 0 ? L[i-1] : 1;
        int backward = i + 1 < A.size() ? R[i+1] : 1;
        maxProduct = max(maxProduct, forward*backward);
    }
    return maxProduct;
}

#endif /* findbiggestMinusOne_h */
