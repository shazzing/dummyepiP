//
//  main.cpp
//  graphs
//
//  Created by shashank hegde on 8/1/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include "shortestLineProg.h"
#include "teamPhoto.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> retVec = getShortestStraightLine(15);
    for(const int& a: retVec){
        cout << a << " " ;
    }
    cout << endl;
    
    return 0;
}
