//
//  MaximizeFishingCatch.h
//  DSDynamicProgramming
//
//  Created by shashank hegde on 1/5/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef MaximizeFishingCatch_h
#define MaximizeFishingCatch_h
#include <vector>

using namespace std;

int maximizeFishing(vector<vector<int>> fishesFound)
{
    for(int i=0; i<fishesFound.size(); i++)
    {
        for(int j=0; j<fishesFound[i].size(); j++)
        {
            fishesFound[i][j] += max((i<1 ? 0:fishesFound[i-1][j]),(j<1 ? 0 : fishesFound[i][j-1] ));
        }
    }
    return fishesFound.back().back();
}

#endif /* MaximizeFishingCatch_h */
