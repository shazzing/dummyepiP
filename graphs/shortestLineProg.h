//
//  shortestLineProg.h
//  graphs
//
//  Created by shashank hegde on 5/19/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef shortestLineProg_h
#define shortestLineProg_h
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<int> getShortestStraightLine(int n){
    if(n==1){
        return {1};
    }
    queue<vector<int>> slps;
    slps.emplace(1,1);
    while(!slps.empty()){
        vector<int> cslp = slps.front();
        slps.pop();
        for(const int &a : cslp){
            int power = a + cslp.back();
            if(power > n){
                break;
            }
            vector<int> new_slp(cslp);
            new_slp.emplace_back(power);
            if(power == n) {
                return new_slp;
            }
            slps.emplace(new_slp);
        }
    }
    return slps.back();
}

#endif /* shortestLineProg_h */
