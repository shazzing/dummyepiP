//
//  teamPhoto.hpp
//  graphs
//
//  Created by shashank hegde on 5/19/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef teamPhoto_h
#define teamPhoto_h
#include <stack>
#include "shortestLineProg.h"

struct graphVertex{
    vector<graphVertex*> edges;
    int maxDistance = 1;
    bool visited = false;
};


void dfs(graphVertex* curr, stack<graphVertex*>* vertex_order){
    curr->visited = true;
    for(const auto& next: curr->edges){
        if(!next->visited){
            dfs(next, vertex_order);
        }
        
    }
    vertex_order->emplace(curr);
}

stack<graphVertex*> buildTopologicalOrdering(vector<graphVertex*>& G ){
    stack<graphVertex*> vertex_order;
    for(auto* g: G){
        if(!g->visited){
            dfs(g, &vertex_order);
        }
    }
    return vertex_order;
}

int findLongestPath(stack<graphVertex*>& vertex_order){
    int maxDistance =0;
    while(!vertex_order.empty()){
        graphVertex* u = vertex_order.top();
        maxDistance = max(maxDistance, u->maxDistance);
        for(graphVertex*& v : u->edges){
            v->maxDistance = max(v->maxDistance, u->maxDistance + 1);
        }
        vertex_order.pop();
    }
    return maxDistance;
}

int findLargestNumberTeams(vector<graphVertex*> G){
    stack<graphVertex*> vertex_order(buildTopologicalOrdering(G));
    return findLongestPath(vertex_order);
}

#endif /* teamPhoto_h */
