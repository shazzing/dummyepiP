//
//  positionAttackedByRook.h
//  epi
//
//  Created by shashank hegde on 8/6/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef positionAttackedByRook_h
#define positionAttackedByRook_h
#include <vector>
#include <utility>
//#include <experimental/numeric>

using namespace std;

void updatePositionPossiblyAttackedByRook(vector<vector<int>>& positions){
    bool zero_first_row = false, zero_first_col = false;
    
    // check if first row has zero
    for(size_t i=0; i < positions[0].size(); i++){
        if(!positions[0][ i]){
            zero_first_row = true;
            break;
        }
    }
    //check if first col has zero
    for(size_t i=0; i < positions.size(); i++){
        if(!positions[i][ 0]){
            zero_first_col = true;
            break;
        }
    }
    
    for(size_t i=1; i<positions.size(); i++){
        for(size_t j=1; j< positions[0].size(); j++){
            if(!positions[i][j]){
                positions[0][j] = 0; //for column update
                positions[i][0] = 0; // for row update
            }
        }
    }
    
    // update all rows that can be attached by rook
    for(size_t i=0; i<positions.size(); i++){
        if(!positions[i][0]){
            for(size_t j=1; j< positions[0].size(); j++){
                positions[i][j] =0;
            }
        }
    }
    
    // update all cols that can be attached by rook
    for(size_t i=0; i<positions[0].size(); i++){
        if(!positions[0][i]){
            for(size_t j=1; j< positions.size(); j++){
                positions[j][i] =0;
            }
        }
    }
    
    if(zero_first_row){
        for(size_t i=0; i<positions[0].size(); i++){
            positions[0][i] =0;
        }
    }
    if(zero_first_col){
        for(size_t j=0; j<positions.size(); j++){
            positions[j][0] = 0;
        }
    }
}

#endif /* positionAttackedByRook_h */
