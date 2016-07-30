//
//  findMaximumWeightPath.h
//  DSDynamicProgramming
//
//  Created by shashank hegde on 1/9/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef findMaximumWeightPath_h
#define findMaximumWeightPath_h
#include <vector>

using namespace std;

int findMinimumTotal(const vector<vector<int>>& triangle)
{
    if(triangle.empty())
        return 0;
    vector<int> prev_row(triangle.front());
    for(size_t i=1; i<triangle.size(); i++)
    {
        vector<int> curr_row(triangle[i ]);
        curr_row.front() += prev_row.front();
        for(size_t j=1; i< curr_row.size()-1; j++)
        {
            curr_row[j] += min(prev_row[j-1], prev_row[j]);
        }
        curr_row.back() += prev_row.back();
        prev_row.swap(curr_row);
    }
    return *min_element(prev_row.cbegin(), prev_row.cend());
}

#endif /* findMaximumWeightPath_h */
