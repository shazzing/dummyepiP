//
//  prePostOrderTraversalnonRecurs.hpp
//  epi
//
//  Created by shashank hegde on 8/14/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef prePostOrderTraversalnonRecurs_h
#define prePostOrderTraversalnonRecurs_h
#include <utility>
#include <memory>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

template<typename T>
struct binaryNode{
    T data;
    unique_ptr<binaryNode<T>> left, right;
    
    binaryNode(T dat, unique_ptr<binaryNode<T>>& l, unique_ptr<binaryNode<T>>& r) : data(dat), left(l), right(r)
    {
        
    }
    
    
};

//template <typename T>
vector<int> preOrderTraversal(const unique_ptr<binaryNode<int>>& tree){
    vector<int> preOrderSeq;
    queue<binaryNode<int>*> preOrder_q;
    preOrder_q.emplace(tree.get());
    while(!preOrder_q.empty()){
        binaryNode<int>* curr = preOrder_q.front();
        preOrder_q.pop();
        if(!curr){
            continue;
        }
        preOrderSeq.emplace_back(curr->data);
        preOrder_q.emplace(curr->left.get());
        preOrder_q.emplace(curr->right.get());
        
    }
    return preOrderSeq;
}

vector<int> preOrderTraversal2(const unique_ptr<binaryNode<int>>& tree){
    vector<int> preOrderSeq;
    stack<binaryNode<int>*> preOrder_q;
    preOrder_q.emplace(tree.get());
    while(!preOrder_q.empty()){
        binaryNode<int>* curr = preOrder_q.top();
        preOrder_q.pop();
        if(!curr){
            continue;
        }
        preOrderSeq.emplace_back(curr->data);
        preOrder_q.emplace(curr->right.get());
        preOrder_q.emplace(curr->left.get());
        
    }
    return preOrderSeq;
}


vector<int> postOrderTraversal(const unique_ptr<binaryNode<int>>& tree){
    vector<int> postOrder_seq;
    stack<binaryNode<int>*> post_stk;
    binaryNode<int>* prev= nullptr;
    post_stk.emplace(tree.get());
    while(!post_stk.empty()){
        binaryNode<int>* curr = post_stk.top();
        if(prev == nullptr || prev->left.get()  == curr || prev->right.get() == curr){ // currently descending BST
            if(curr->left != nullptr){
                post_stk.push(curr->left.get());
            }
            else if(curr->right != nullptr){
                post_stk.push(curr->right.get());
            }
            else{
                post_stk.pop();
                postOrder_seq.emplace_back(curr->data);
            }
        }
        else if(curr->left.get() == prev){//left traversal done
            if(curr->right != nullptr){
                post_stk.push(curr->right.get());
            }
            else{
                postOrder_seq.emplace_back(curr->data);
                post_stk.pop();
            }
        }
        else{ //both left and right children traversal is done
            postOrder_seq.emplace_back(curr->data);
            post_stk.pop();
        }
        prev = curr;
    }
    return postOrder_seq;
}


#endif /* prePostOrderTraversalnonRecurs_h */
