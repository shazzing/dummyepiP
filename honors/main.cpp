//
//  main.cpp
//  honors
//
//  Created by shashank hegde on 8/1/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include "minPositiveMissingNum.hpp"
#include "findbiggestMinusOne.h"
#include "buyAndSellStockKtimes.hpp"
#include "manIncreasingSeq.hpp"
using namespace std;

void honorsTest(){
    
    cout << "###### Running minPositiveNum test ########### " << endl;
    vector<int> arr = {3, 5, 4, -1, 5, 1, -1};
    int minPositiveVal = findMinPositiveMissingNum1(arr);
    cout << " minPositiveNum is: " << minPositiveVal << endl;
    
    cout << "###### Running maxProductofAllButOne test ########### " << endl;
    int maxProductVal = maxProductMinusOne(arr);
    cout << "maxProductofAllButOne element is:" << maxProductVal << endl;
    
    vector<double> prices = {55.4, 57.3, 50.9, 44.45, 78.33, 22.44};
    double maxProfit = maxProfitFromStock(prices, 2);
    
    cout << "maxProfit for the price series is" << maxProfit << endl;
    
    vector<int> A = {2, 11, 3, 5, 13, 7, 19, 17, 23};
    pair<int, int> result = maxIncreasingSeqLen(A);
    
    cout << "maxIncreasing sequence is : {" << result.first << ", " << result.second << " }." << endl;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    honorsTest();
    return 0;
}
