//
//  reverseSubListofKSize.hpp
//  epi
//
//  Created by shashank hegde on 8/7/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef reverseSubListofKSize_h
#define reverseSubListofKSize_h
#include <string>
#include <vector>
#include <cmath>
#include <memory>
using namespace std;

struct linkedList{
    int data;
    linkedList* next=nullptr;
    linkedList(int dat, linkedList* lst=nullptr){
        data = dat;
        next = lst;
    }
};

size_t lengthOfList(linkedList* head){
    size_t len=0;
    linkedList* curr_elem = head;
    while(curr_elem){
        len++;
        curr_elem = curr_elem->next;
    }
    return len;
}

linkedList* reverseSubListofKSize(linkedList* head, int k){
    size_t sz = lengthOfList(head);
    size_t num_of_sublist = floor(static_cast<double>(sz/k)), sublist_index = 0, sublist_offset = 0;
    linkedList *currHead = head, *curr_elem = head, *next_elem = nullptr, *prev_elem = nullptr, *dummy_head = new linkedList(0,head);
    while(++sublist_index < num_of_sublist && curr_elem){
        while(sublist_offset++ < k && curr_elem){
            next_elem = curr_elem->next;
            curr_elem->next = prev_elem;
            prev_elem  = curr_elem;
            curr_elem = next_elem;
        }
        if(sublist_index==1){
            dummy_head->next = curr_elem;
        }
        sublist_offset = 0; // reset
        currHead->next = next_elem;
        currHead = currHead->next;
       
    }
    return dummy_head->next;
}

// basic reverseLinkedList
linkedList* reverseList(linkedList* head){
    if(!head || !head->next){
        return head; // base condition
    }
    linkedList *curr =head, *prev = nullptr;
    while(curr){
        linkedList* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

linkedList* reverseKList(linkedList* head, int k){
    linkedList* dummy_head = new linkedList(0,head), *sublist_pred = dummy_head, *sublist_head = dummy_head->next,
                                                        *sublist_succ = dummy_head, *sublist_tail = dummy_head->next;
    while(sublist_head){
        int num_rem = k;
        while(num_rem){
            sublist_succ = sublist_tail;
            sublist_tail = sublist_tail->next;
            --num_rem;
            if(!sublist_tail){ // means less than k elems so no need to reverse
                break;
            }
        }
        if(num_rem > 0){ // no need to reverse here, just return the dummy_head->next
            return dummy_head->next;
        }
       // we know now we have to reverse, break the list at end
        sublist_succ->next = nullptr;
        reverseList(sublist_head);
        
        // connect predeccessor sublist with successor
        sublist_pred->next = sublist_succ;
        sublist_pred = sublist_head;
        sublist_head->next = sublist_tail;
        sublist_head = sublist_tail; // move step forward
        sublist_succ = nullptr;
        
    }
    
    return dummy_head->next;
}



#endif /* reverseSubListofKSize_h */
