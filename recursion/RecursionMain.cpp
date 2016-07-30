//
//  main.cpp
//  Recursion
//
//  Created by shashank hegde on 12/19/15.
//  Copyright (c) 2015 shashank hegde. All rights reserved.
//

#include <iostream>
#include <vector>
#include "TowerOfHanoi.h"
#include "NonAttackingQueenPlacement.h"
#include "PermutationGenerate.h"
#include "PowerSet.h"
#include "SubSetofCertainSize.h"
#include "MatchedParen.h"
#include "PalindromePartitioning.h"

using namespace std;

int main(int argc, const char * argv[]) {
 
    
    // Test1: TowerofHanoi
    cout << "Running TowerOfHanoiTest" << endl << "==========================" << endl;
    computeTowerOfHanoi(4);
    cout << "finished test" << "===========" <<endl << endl;
    
    // Test2: NonAttackingQueenPlacement
    cout << "Running NonAttackingQueens" << endl << "==========================" << endl;
    vector<vector<int>> result = nQueens(4);
    for(auto placement:result)
    {
        cout << "the placement is: ";
        for(auto val:placement)
        {
            cout << " " << val;
        }
        cout << endl;
    }
    cout << "finished test" << "===========" <<endl << endl;
    //Test3: generate Permuation
    cout << "Generating permutation" << endl << "=========================" << endl;
    vector<int> input;
    input.emplace_back(2);
    input.emplace_back(3);
    input.emplace_back(5);
    input.emplace_back(7);
    vector<vector<int>> newResult = permutation(input);
    for(auto res:newResult)
    {
        cout << "permutation values: ";
        for(auto val:res)
        {
            cout << " " << val;
        }
        cout << endl;
    }
    cout << "finished test" << "===========" <<endl << endl;
    
    cout << "Generating powerset" << endl << "=========================" << endl;
    vector<int> inp;
    inp.emplace_back(2);
    inp.emplace_back(3);
    inp.emplace_back(5);
    inp.emplace_back(7);
    vector<vector<int>> Result1 = powerSet(input);
    for(auto res:Result1)
    {
        cout << "powerset values: ";
        for(auto val:res)
        {
            cout << " " << val;
        }
        cout << endl;
    }
    cout << "finished test" << "===========" <<endl << endl;
    
    cout << "Generating subset of size[2] from rangle till[5]" << endl << "=========================" << endl;
    vector<vector<int>> result3 = subsetOfCertainSize(5,2);
    for(auto res:result3)
    {
        cout << "subset values: ";
        for(auto val:res)
        {
            cout << " " << val;
        }
        cout << endl;
    }
    cout << "finished test" << "===========" <<endl << endl;
    
    cout << "generating matching parenthesis of size[4]" << endl << "=========================" << endl;
    vector<string> parenthesisStr = generateBalancedParanthesis(4);
    cout << "matching parenthesis are: " ;
    for(string str:parenthesisStr)
    {
        cout << str <<endl;
    }
    cout << "finished test" << "===========" <<endl << endl;
    
    cout << "generating palindrome decompositon of string[0204451881]" << endl
    <<"=========================" << endl;
    vector<vector<string>> result4 = palindromeDecomposition("0204451881");
    for(auto res:result4)
    {
        cout << "displaying another combination: ";
        for(auto val:res)
        {
            cout << " " << val;
        }
    }
    cout << "finished test" << "===========" <<endl << endl;
    return 0;
}
