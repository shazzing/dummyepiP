//
//  medianCirList.hpp
//  epi
//
//  Created by shashank hegde on 8/11/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef medianCirList_h
#define medianCirList_h
#include "reverseSubListofKSize.hpp"
using namespace std;

double findMedianOfCircularLinkedList(linkedList* rNode){
    int listSz = 1;
    linkedList *minNode = rNode, *iter = rNode;
    while(iter && iter != rNode){
        if(iter->data <= minNode->data ){
            minNode = iter;
        }
        listSz++;
        iter = iter->next;
    }
    
    bool isLenEven = listSz%2 ? false : true;
    int medianElem = listSz/2, currIndex = 0;
    iter = minNode;
    while(iter && currIndex++ < medianElem){
        iter = iter->next;
    }
    
    double median = isLenEven ? (iter->data + iter->next->data)/2.0 : iter->data/2.0;
    return median;
}

#endif /* medianCirList_h */
