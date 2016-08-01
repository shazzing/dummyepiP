//
//  minPositiveMissingNum.hpp
//  epi
//
//  Created by shashank hegde on 7/31/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef minPositiveMissingNum_h
#define minPositiveMissingNum_h
#include <vector>
using namespace std;

int findMinPositiveMissingNum(vector<int>& arr){
    int i=0;
    while(i < arr.size()){
        if( arr[i] > 0 && arr[i] < arr.size() && arr[i] != arr[arr[i]]){
            swap(arr[i], arr[arr[i]]);
        }
        else{
            i++;
        }
    }
    for(int i=1; i<arr.size(); i++){
        if(arr[i] != i){
            return i;
        }
            
    }
    return arr.size();
}

// textBooks soln

int findMinPositiveMissingNum1(vector<int>& arr){
    size_t i=0;
    while(i < arr.size()){
        if( arr[i] > 0 && arr[i] <= arr.size() && arr[i] != arr[arr[i]-1]){
            swap(arr[i], arr[arr[i]-1]);
        }
        else{
            i++;
        }
    }
    for( i=1; i<arr.size(); i++){
        if(arr[i] != i+1){
            return i+1;
        }
        
    }
    return arr.size() + 1;
}


#endif /* minPositiveMissingNum_h */
