//
//  longestValidParanthesis.h
//  epi
//
//  Created by shashank hegde on 8/11/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef longestValidParanthesis_h
#define longestValidParanthesis_h
#include <string>
#include <stack>
#include <numeric>
using namespace std;

size_t longestValidPara(const string& paraStr){
    size_t maxLength = 0, end=0;
    stack<size_t> leftParaStk;
    for(size_t i=0; i< paraStr.size(); i++){
        if(paraStr[i] == '('){
            leftParaStk.push(i);
        }
        else if(leftParaStk.empty()){
            end = i;
        }
        else{
            leftParaStk.pop();
            size_t start = leftParaStk.empty() ? end : leftParaStk.top();
            maxLength = max(maxLength, i-start);
        }
    }
    return maxLength;
}

#endif /* longestValidParanthesis_h */
