//
//  bedBathBeyondProb.h
//  DSDynamicProgramming
//
//  Created by shashank hegde on 1/8/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef bedBathBeyondProb_h
#define bedBathBeyondProb_h
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

vector<string> wordBreaking(const string& a, const unordered_set<string>& dict)
{
    vector<int> T(a.size(), 0);
    for(int i=0; i< a.size(); i++)
    {
        if(dict.find(a.substr(0, i+1)) != dict.cend())
        {
            T[i] =i + 1;
        }
        for(int j=0; j<i && T[i] == 0; j++)
        {
            if(T[j] != 0 && dict.find(a.substr(j+1, i-j)) != dict.cend())
            {
                T[i] = i-j;
            }
        }
    }
    
    vector<string> ret;
    if(T.back()) {
        int idx = a.size() -1;
        while(idx >0)
        {
            ret.emplace_back(a.substr(idx-T[idx]+1, T[idx]));
            idx -= T[idx];
        }
        reverse(ret.begin(), ret.end());
    }
    return ret;
}

#endif /* bedBathBeyondProb_h */
