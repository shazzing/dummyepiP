//
//  graphFaultTolerant.h
//  epi
//
//  Created by shashank hegde on 8/27/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef graphFaultTolerant_h
#define graphFaultTolerant_h

#include <vector>
#include <numeric>

using namespace std;

struct graphVertex{
    int l, d; // d-> discoverey l-> leavingtime
    vector<graphVertex*> edges;
    graphVertex(int lev, int disc, const vector<graphVertex*>& ed) : l(lev), d(disc), edges(ed){
    }
};

bool has_bridge(graphVertex* curr, graphVertex* prev, int time){
    curr->d =            time++;
    curr->l = numeric_limits<int>::max();
    for(graphVertex* next: curr->edges){
        if(next != prev){ // no cycle
            if(next->d != 0){ // back edge
                curr->l = min(curr->l, next->d);
            }
            else{ //forward edge
                if(!has_bridge(next, curr, time)){
                    return false;
                }
                curr->l = min(curr->l, next->l);
            }
        }
    }
    return (prev == nullptr || curr->l < curr->d);
}

bool isGraphFaultTolerant(vector<graphVertex*>* G){
    if(!G->empty()){
        return has_bridge(G->front(), nullptr, 0);
    }
    return true;
}

#endif /* graphFaultTolerant_h */
