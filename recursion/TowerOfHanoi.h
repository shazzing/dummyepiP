//
//  TowerOfHanoi.h
//  Recursion
//
//  Created by shashank hegde on 12/19/15.
//  Copyright (c) 2015 shashank hegde. All rights reserved.
//
#include <iostream>
#include <array>
#include <stack>
using namespace std;
#ifndef Recursion_TowerOfHanoi_h
#define Recursion_TowerOfHanoi_h

const int numPegs = 3;
void computeTowerOfHanoiHelper(int num_rings, array<stack<int>, numPegs>* pegs,
                               int srcIndex, int destIndex, int usingIndex);
void computeTowerOfHanoi(int num_rings)
{
    array<stack<int>, numPegs> pegs;
    for(int i=num_rings; i>0; --i)
    {
        pegs[0].push(i);
    }
    computeTowerOfHanoiHelper(num_rings, &pegs, 0, 1, 2);
}

void computeTowerOfHanoiHelper(int num_rings, array<stack<int>, numPegs>* pegs,
                               int srcIndex, int destIndex, int usingIndex)
{
    if(num_rings==1)
    {
        cout << "Moving ring[" << num_rings << "], peg from[" << srcIndex << "], peg to[" << destIndex << "]." << endl;
        return;
    }
    computeTowerOfHanoiHelper(num_rings-1, pegs, srcIndex, usingIndex, destIndex);
    cout << "Finally: moving ring[" << num_rings << "], peg from[" << srcIndex << "], peg to[" << destIndex << "]." << endl;
    computeTowerOfHanoiHelper(num_rings-1, pegs, usingIndex, destIndex, srcIndex);
    
}

#endif
