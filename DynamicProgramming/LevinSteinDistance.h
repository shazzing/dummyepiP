//
//  LevinSteinDistance.h
//  DSDynamicProgramming
//
//  Created by shashank hegde on 1/3/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef LevinSteinDistance_h
#define LevinSteinDistance_h
#include <string>
#include <numeric>

using namespace std;

int levistienDistance(string A, string B)
{
    if(A.size() < B.size())
    {
        swap(A, B);
    }
    
    vector<int> D(B.size()+ 1);
    iota(D.begin(), D.end(), 0);
    for(int i=1; i<=A.size(); ++i)
    {
        int pre_i_1_j_1 = D[0]; // Stores the value of D[]i-1][j-1]
        D[0] = i;
        for(int j=1; j<= B.size(); ++j)
        {
            int pre_i_1_j = D[j];
            D[j] = A[i-1] == B[j-1] ? pre_i_1_j_1 : 1 + (min(pre_i_1_j_1, min(D[j-1], D[j])));
            pre_i_1_j_1 = pre_i_1_j;
        }
    }
    return D.back();
}

#endif /* LevinSteinDistance_h */
