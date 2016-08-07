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
#include "rotateArr.hpp"
#include "positionAttackedByRook.h"
#include "justifyText.hpp"
using namespace std;

void display2DArr(const vector<vector<int>>& position){
    for(size_t i=0; i<position.size(); i++){
        for(size_t j=0; j < position[0].size(); j++){
            cout << position[i][j] << " ";
        }
        cout << endl;
    }
}

void honorsTest(){
    /*
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
    
    vector<int> A = {2, 11, 3, 5, 13, 17, 19, 17, 23};
    pair<int, int> result = maxIncreasingSeqLen(A);
    
    cout << "maxIncreasing sequence is : {" << result.first << ", " << result.second << " }." << endl;
    
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    rotateArr(6, arr1);
    
    for(int a:arr1){
        cout << a << ", " ;
    }
    cout << endl;
    */
    vector<vector<int>> positions(8, vector<int>(8,1));
    
    positions[0][1] =0, positions[3][5] =0, positions[4][3] =0, positions[6][0] =0;
    positions[6][5] = 0;
    
    cout << "current positions is " << endl;
    display2DArr(positions);
    updatePositionPossiblyAttackedByRook(positions);
    cout << "new positions are " << endl;
    display2DArr(positions);
    
    vector<string> words = {"The", "quick", "brown", "fox", "jumped", "over", "the", "lazy", "dogs."};
    vector<string> res = justifyText(words, 11);
    for(string line:res){
        cout << line << endl;
    }
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    honorsTest();
    return 0;
}
