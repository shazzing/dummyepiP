//
//  traverse2DArray.h
//  DSDynamicProgramming
//
//  Created by shashank hegde on 1/5/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef traverse2DArray_h
#define traverse2DArray_h
#include <vector>
#include <queue>

using namespace std;

int numofWays(int n, int m)
{
    if(n<m)
        swap(n,m);
    vector<int> arr(m,1);
    for(int i=1; i<n; i++)
    {
        int prev_res = 0;
        for(int j=0; j<m; j++)
        {
            arr[j] = arr[j] + prev_res;
            prev_res = arr[j];
        }
    }
    return arr[m-1];
}

int numofWaysWithObstacles(int n, int m, const vector<deque<bool>>& b)
{
    vector<vector<int>> A(n, vector<int>(m,0));
    if(b[0][0]){
        return 0;
    }
    A[0][0] = 1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j <m; j++)
        {
            A[i][j] += (i<1 ? 0 : A[i-1][j]) + (j<1 ?0 :A[i][j-1]);
        }
    }
    return A.back().back();
}

#endif /* traverse2DArray_h */
