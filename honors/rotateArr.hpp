//
//  rotateArr.hpp
//  epi
//
//  Created by shashank hegde on 8/6/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef rotateArr_h
#define rotateArr_h
#include <vector>
#include <utility>
//#include <experimental/numeric>

using namespace std;


void applycyclicPermutation(int rotateAmt, int offset, int cycle_size, vector<int>& A){
    int temp = A[offset];
    for(int i=1; i< cycle_size; i++){
        swap(A[(offset + i + rotateAmt)%A.size()], temp);
    }
    A[offset] = temp;
}


void rotateArr(int rotateAmt, vector<int>& A){
    rotateAmt %= A.size();
    int num_cycles = 3 ;// gcd(rotateAmt, A.size());
    int cycle_size = A.size()/num_cycles;
    
    for(int c=0; c<num_cycles; c++){
        applycyclicPermutation(rotateAmt, c, cycle_size, A);
    }
}

void rotateArr1(int i, vector<int>& A){
    i %= A.size();
    reverse(A.begin(), A.end());
    reverse(A.begin(), A.begin() + i);
    reverse(A.begin() + i, A.end());
}
#endif /* rotateArr_h */
