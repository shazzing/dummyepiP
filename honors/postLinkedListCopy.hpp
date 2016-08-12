//
//  postLinkedListCopy.hpp
//  epi
//
//  Created by shashank hegde on 8/10/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef postLinkedListCopy_h
#define postLinkedListCopy_h

struct linkListP{
    int data;
    linkListP* next;
    linkListP* jump;
};

linkListP* createCopyOfList(linkListP* head){
    
    //create a copy of list with associating orig listNode to its copyList counterparts
    linkListP* iter = head;
    while(iter)
    {
        linkListP* newNode = new linkListP(iter->data, iter->next, nullptr);    // create jump linkage on copies list
        iter->next = newNode
        iter = iter->next->next;
    }
    

    iter = head;
    while(iter && iter->next){
        iter->next->jump = iter->jump->next;
        iter = iter->next->next;
    }
    
    iter = head;
    linkListP* newHead = iter->next;
    // now break the linkage between copy and original linkedList and set next linkage for copyList
    
    while(iter->next){
        linkListP* nxt = iter->next;
        iter->next = nxt->next;
        iter = nxt;
    }
    return newHead;
}


#endif /* postLinkedListCopy_h */
