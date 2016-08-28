//
//  findLongestSubArrLessThanK.hpp
//  epi
//
//  Created by shashank hegde on 8/28/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//  22.46

#ifndef findLongestSubArrLessThanK_h
#define findLongestSubArrLessThanK_h
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

pair<int, int> findLongestSubArrLessThanK(const vector<int>& arr, int k){
    vector<int> prefix_sum;
    partial_sum(arr.begin(), arr.end(), back_inserter(prefix_sum));
    if(prefix_sum.back() <= k){
        return {0, arr.size()-1};
    }
    
    // build min-prefix sum
    vector<int> min_prefix_sum(arr.size(), 0);
    min_prefix_sum.back() = prefix_sum.back();
    
    /*  1. if u < v such that prefix_sum[u] > prefix_sum[v], u cannot be the endpoint of solution
        2. The reason for above is for any w < u, if A[w:u] satisfies the sum constraint, so should A[w:v] and w:v is longer than w:u
        3.  1 and 2 motivates the definitiion of min_partial_sum(q) such that q[i] = min(p[i], q[i+1]) for i > n-1 and q[n-1] = p[n-1]
     */
    for(int i=arr.size()-2; i>=0; --i){
        min_prefix_sum[i] = min(prefix_sum[i], min_prefix_sum[i+1]);
    }
    
    int a=0, b=0, max_length =0;
    pair<int, int> res_idx = {-1, -1};
    
    while(a<arr.size() && b < arr.size()){
        int min_curr_sum = a > 0 ? min_prefix_sum[b] - prefix_sum[a-1] : min_prefix_sum[b];
        if(min_curr_sum <= k){
            int curr_length = b - a + 1;
            if(curr_length > max_length){
                max_length = curr_length;
                res_idx = {a, b};
            }
            ++b;
        }
        else{
            ++a;
        }
    }
    
    return res_idx;
    
}


#endif /* findLongestSubArrLessThanK_h */
