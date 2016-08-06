//
//  buyAndSellStockKtimes.hpp
//  epi
//
//  Created by shashank hegde on 8/1/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef buyAndSellStockKtimes_h
#define buyAndSellStockKtimes_h

#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
using namespace std;

double maxProfitFromStock(const vector<double>& prices, int k){
    vector<double> k_sum(2*k, numeric_limits<double>::lowest());
    for(int i=0; i < prices.size(); i++){
        vector<double> pre_k_sum(k_sum);
        for(int j=0, sign = -1; j < k_sum.size() && j <=i ; j++, sign *= -1){
            double diff = sign*prices[i] + ( j == 0 ? 0 : pre_k_sum[j-1] );
            k_sum[j] = max(diff, pre_k_sum[j]);
        }
    }
    return k_sum.back();
}

#endif /* buyAndSellStockKtimes_h */
