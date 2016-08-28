//
//  addRoadNetworkreduceDistance.h
//  epi
//
//  Created by shashank hegde on 8/28/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef addRoadNetworkreduceDistance_h
#define addRoadNetworkreduceDistance_h
#include <numeric>
#include <vector>

using namespace std;

const double maxDouble = numeric_limits<double>::max();

struct highwaySection{
    int x, y;
    double distance;
};

void floydWarshall(vector<vector<double>>& G){
    for(int k=0; k<G.size(); ++k){
        for(int i=0; i< G.size(); ++i){
            for(int j=0; j < G.size(); ++j){
                if(G[i][k] != maxDouble && G[j][k] !=  maxDouble && G[i][j] > G[i][k] + G[k][j]){
                    G[i][j] = G[i][k] + G[k][j];
                    //G[j][i] = G[i][j];
                }
            }
        }
    }
}

highwaySection findBestProposal(const vector<highwaySection>& h, const vector<highwaySection>& proposals, int a, int b, int n){
    vector<vector<double>> G(n, vector<double>(n, maxDouble));
    for(int i=0; i<n; ++i){
        G[i][i] =0;
    }
    
    for(const highwaySection& hg: h){
        G[hg.x][hg.y] = hg.distance;
    }
    
    // perform floyd-warshall to get the shortest distance between vertices before introducing proposals
    floydWarshall(G);
    
    // Examine each proposal for shorter distance between a and b
    
    double min_dis_a_b = G[a][b];
    highwaySection bestProposal = {-1, -1, 0};
    
    for(const highwaySection& p: proposals){
        // check the path a=>p.x=>p.y=>b
        if( G[a][p.x] != maxDouble &&
            G[p.y][b] != maxDouble &&
           min_dis_a_b > G[a][p.x] + p.distance + G[p.y][b]){
            min_dis_a_b = G[a][p.x] + p.distance + G[p.y][b];
            bestProposal = p;
        }
        // check the path a=>p.y=>p.x=>b
        else if(G[a][p.y] != maxDouble &&
                G[p.x][b] != maxDouble &&
                min_dis_a_b > G[a][p.y] + p.distance + G[p.x][b]){
            min_dis_a_b = G[a][p.y] + p.distance + G[p.x][b];
            bestProposal = p;
        }
    }
    return bestProposal;
}

#endif /* addRoadNetworkreduceDistance_h */
