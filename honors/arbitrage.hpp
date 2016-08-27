//
//  arbitrage.hpp
//  epi
//
//  Created by shashank hegde on 8/27/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef arbitrage_h
#define arbitrage_h
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

bool bellmanFord(const vector<vector<double>>& G, int source){
    vector<double> dis_to_source(G.size(), numeric_limits<double>::max());
    dis_to_source[source] =0;
    double max_double = numeric_limits<double>::max();
    for(size_t times=1; times < G.size(); ++times){
        bool has_update = false;
        for(size_t i=0; i< G.size(); ++i){
            for(size_t j=0; j < G.size(); ++j){
                if(dis_to_source[i] != max_double && dis_to_source[j] > dis_to_source[i] + G[i][j]){
                    dis_to_source[j] = dis_to_source[i] + G[i][j];
                    has_update = true;
                }
            }
        }
        
        // no update on this iteration means no cycles
        if(!has_update){
            return false;
        }
        
        //detect cycle if there are any further updates
        for(size_t i=0; i< G.size(); ++i){
            for(size_t j=0; j < G.size(); ++j){
                if(dis_to_source[i] != max_double && dis_to_source[j] > dis_to_source[i] + G[i][j]){
                    return true;
                }
            }
        }
    }
    return false;
}

bool doesArbitrageExist(vector<vector<double>>& G){
    for(vector<double>& edge_list:G){
        for(double& edge: edge_list){
            edge = -log10(edge);
        }
    }
    return bellmanFord(G, 0);
}


#endif /* arbitrage_h */
