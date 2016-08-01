//
//  main.cpp
//  honors
//
//  Created by shashank hegde on 7/30/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include "minPositiveMissingNum.hpp"
#include "findbiggestMinusOne.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arr = {3, 5, 4, -1, 5, 1, -1};
    int minPositiveVal = findMinPositiveMissingNum1(arr);
    cout << " minPositiveNum is: " << minPositiveVal << endl;
    return 0;
}
