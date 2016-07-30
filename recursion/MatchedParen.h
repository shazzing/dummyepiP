//
//  MatchedParen.h
//  Recursion
//
//  Created by shashank hegde on 12/20/15.
//  Copyright (c) 2015 shashank hegde. All rights reserved.
//

#ifndef Recursion_MatchedParen_h
#define Recursion_MatchedParen_h
#include <vector>
#include <string>
using namespace std;

void generateBalancedParanthesisHelper(int num_left_pairs_neeeded, int num_right_pairs_needed,
                                       const string valid_prefix, vector<string>* result )
{
    if(!num_left_pairs_neeeded && !num_right_pairs_needed)
    {
        result->emplace_back(valid_prefix);
        return;
    }
    if(num_left_pairs_neeeded)
    {
        generateBalancedParanthesisHelper(num_left_pairs_neeeded-1, num_right_pairs_needed, valid_prefix + '(', result);
    }
    if(num_left_pairs_neeeded < num_right_pairs_needed)
    {
        generateBalancedParanthesisHelper(num_left_pairs_neeeded, num_right_pairs_needed-1,
                                            valid_prefix + ')',result);
    }
}

vector<string> generateBalancedParanthesis(int num_pairs)
{
    vector<string> result;
    generateBalancedParanthesisHelper(num_pairs, num_pairs, "", &result);
    return result;
}
#endif
