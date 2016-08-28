//
//  elemThatAppearsMoreTimes.hpp
//  epi
//
//  Created by shashank hegde on 8/28/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef elemThatAppearsMoreTimes_h
#define elemThatAppearsMoreTimes_h

#include "justHeaders.hpp"

vector<string> searchFrequentItems(stringstream* sstr, int k){
    string buf;
    unordered_map<string, int> hashM;
    int n = 0;
    while(*sstr >> buf){
        n++;
        hashM[buf]++;
        if(hashM.size() == k){
            auto it = hashM.begin();
            while(it != hashM.end()){
                if(--(it->second) == 0){
                    hashM.erase(it);
                }
                it++;
            }
        }
    }
    
    // reset count for the k elements
    for(auto& it:hashM){
        it.second = 0;
    }
    
    sstr->clear();
    sstr->seekg(0, ios::beg);
    
    while(*sstr >> buf){
        auto it = hashM.find(buf);
        if(it != hashM.end()){
            it->second++;
        }
    }
    
    // select the word only if appears > n/k times
    vector<string> ret;
    
    for(const pair<string, int>& it : hashM){
        if(it.second > static_cast<double>(n)/k){
            ret.emplace_back(it.first);
        }
    }
    return ret;
}


#endif /* elemThatAppearsMoreTimes_h */
