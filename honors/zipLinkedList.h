//
//  zipLinkedList.h
//  epi
//
//  Created by shashank hegde on 8/10/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef zipLinkedList_h
#define zipLinkedList_h
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include "reverseSubListofKSize.hpp"

//using namespace std;

linkedList* zipLinkList(linkedList* head){
    linkedList* fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next, slow = slow = slow->next;
    }
    linkedList* firstH_head = head, *secondH_head = slow->next;
    slow->next = nullptr; //break off the link between first half and second
    secondH_head = reverseList(secondH_head);
    
    while(firstH_head && secondH_head){
        linkedList* firstHNext = firstH_head->next, *secondH_next = secondH_head->next;
        firstH_head->next = secondH_head;
        secondH_head->next = firstHNext;
        firstH_head = firstHNext;
        secondH_head = secondH_next;
    }
    return head;
}

#endif /* zipLinkedList_h */
