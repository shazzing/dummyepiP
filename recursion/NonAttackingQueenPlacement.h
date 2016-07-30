//
//  NonAttackingQueenPlacement.h
//  Recursion
//
//  Created by shashank hegde on 12/19/15.
//  Copyright (c) 2015 shashank hegde. All rights reserved.
//


#ifndef Recursion_NonAttackingQueenPlacement_h
#define Recursion_NonAttackingQueenPlacement_h
#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>* placements);
void solveNQueens(int n, int row, vector<int>* placements, vector<vector<int>>* result);

vector<vector<int>> nQueens(int n)
{
    vector<int> placements;
    vector<vector<int>> result;
    solveNQueens(n, 0, &placements, &result);
    return result;
}

void solveNQueens(int n, int row, vector<int>* placements, vector<vector<int>>* result)
{
    if(row == n)
    {
        result->emplace_back(*placements);
    }
    else
    {
        for(int col=0; col < n; ++col)
        {
            placements->emplace_back(col);
            if(isValid(placements))
            {
                solveNQueens(n, row+1, placements, result);
            }
            placements->pop_back();
        }
    }
}

// checking if the most recent placement is valid. The earlier values are valid only, else would have got popped.
bool isValid(vector<int>* placements)
{
    size_t row_id = placements->size()-1;
    for(size_t i=0; i <row_id; ++i)
    {
        int diff = abs((*placements)[i] - (*placements)[row_id]);
        if(diff == 0  || // columns match
           diff == (row_id-i) // same diagonal
           )
        {
            return false;
        }
    }
    return true;
}

#endif
