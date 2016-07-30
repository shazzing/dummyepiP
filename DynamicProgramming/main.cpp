//
//  main.cpp
//  DSDynamicProgramming
//
//  Created by shashank hegde on 1/3/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include <vector>
#include "countNoScoreCombination.h"
#include "LevinSteinDistance.h"
#include "QuickSort.h"
#include "traverse2DArray.h"
#include "MaximizeFishingCatch.h"
#include "matchSequencein2DArr.h"
#include "knapsackProblem.h"
#include "minimizeDifferenceInSpoil.h"
#include "bedBathBeyondProb.h"
#include "findMaximumWeightPath.h"

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> scoreWeights;
    scoreWeights.push_back(7);
    scoreWeights.push_back(3);
    scoreWeights.push_back(2);
    scoreWeights.push_back(5);
    scoreWeights.push_back(9);
    scoreWeights.push_back(13);
    
    quicksort(scoreWeights, 0, (int)(scoreWeights.size()-1));
    int i=0;
    for(int score:scoreWeights)
    {
        cout << "score[" << i++ << "]=[" << score << "]." << endl;
    }

    cout << "the number of combination in American football to get a score of 12 is: "
            << countCombination(12, scoreWeights) << endl;
    cout << "the number of combination in American football to get a score of 12 is: "
    << countPermutation(12, scoreWeights) << endl;
    cout << " the levistein distance between words 'Carthorse' and 'Orchestra' is: " << levistienDistance("Carthorse", "Orchestra") << endl;
    
    cout << "the numberofWays of trversal of 5,5 2DArray is:" << numofWays(5, 5) << endl;
    
    vector<vector<int>> fishesNums(5, vector<int>(5, 0));
    fishesNums[2][3] = 15;
    fishesNums[0][4] = 11;
    fishesNums[4][3] = 18;
    fishesNums[2][2] = 6;
    cout << "the maximum number of fishes that can be caught are:" << maximizeFishing(fishesNums) << endl;
    
    vector<vector<int>> matchArr(3,vector<int>(3,0));
    matchArr[0][0] = 1;
    matchArr[0][1] = 2;
    matchArr[0][2] = 3;
    matchArr[1][0] = 3;
    matchArr[1][1] = 4;
    matchArr[1][2] = 5;
    matchArr[2][0] = 5;
    matchArr[2][1] = 6;
    matchArr[2][2] = 7;
    
    cout << "does the matchArr match the sequence (1, 3, 4, 6) : " << match(matchArr, vector<int>{1,3,4,6}) << endl;
    
    
    
    return 0;
}
