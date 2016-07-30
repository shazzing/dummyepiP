//
//  matchSequencein2DArr.h
//  DSDynamicProgramming
//
//  Created by shashank hegde on 1/5/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef matchSequencein2DArr_h
#define matchSequencein2DArr_h
#include <vector>
#include <unordered_set>
//#include <hash>


using namespace std;

struct hashTuple
{
    size_t operator()(const tuple<int, int, int>& t)
    {
        return hash<int>()(get<0>(t)) ^ hash<int>()(get<1>(t)) ^ hash<int>()(get<2>(t));
    }
};

bool matchHelper(const vector<vector<int>>& a, const vector<int>& s, int i, int j, int len,
                 unordered_set<tuple<int, int, int>, hashTuple>* cache)
{
    if(s.size() == len)
        return true;
    
    if(i<0 || i >= a.size() || j<0 || j >= a[i].size() || cache->find({i, j, len}) != cache->end() )
       {
           return false;
       }
    if(a[i][j] == s[len] && (matchHelper(a, s, i-1, j, len+1, cache) ||
       matchHelper(a, s, i+1, j, len+1, cache) ||
        matchHelper(a, s, i, j-1, len+1, cache) ||
         matchHelper(a, s, i, j+1, len+1, cache)))
    {
        return true;
    }
       cache->emplace(i,j, len);
       return false;
       
       
}

bool match(const vector<vector<int>>& a, const vector<int>& s)
{
    unordered_set<tuple<int, int, int>, hashTuple> cache;
    for(int i=0; i<a.size(); i++)
    {
        for(int j=0;j<a[i ].size(); j++)
        {
            if(matchHelper(a,s, i, i, 0, &cache ))
               {
                   return true;
               }
        }
    }
    return false;
}

#endif /* matchSequencein2DArr_h */
