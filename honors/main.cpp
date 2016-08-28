//
//  main.cpp
//  honors
//
//  Created by shashank hegde on 8/1/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include "minPositiveMissingNum.hpp"
#include "findbiggestMinusOne.h"
#include "buyAndSellStockKtimes.hpp"
#include "manIncreasingSeq.hpp"
#include "rotateArr.hpp"
#include "positionAttackedByRook.h"
#include "justifyText.hpp"
#include "reverseSubListofKSize.hpp"
#include "zipLinkedList.h"
#include "medianCirList.hpp"
#include "longestValidParanthesis.h"
#include "maxOfSlidingWindow.h"
#include "prePostOrderTraversalnonRecurs.hpp"
#include "powerSet.hpp"
#include "arbitrage.hpp"
#include "graphFaultTolerant.h"
#include "findLongestSubArrLessThanK.hpp"
#include <memory>


using namespace std;

void display2DArr(const vector<vector<int>>& position){
    for(size_t i=0; i<position.size(); i++){
        for(size_t j=0; j < position[0].size(); j++){
            cout << position[i][j] << " ";
        }
        cout << endl;
    }
}

linkedList* makeListFromArray(const vector<int>& arr){
    linkedList* prev =nullptr, *curr = nullptr, *dummy_head = new linkedList(0,nullptr);
    for(int elem: arr){
        curr = new linkedList(elem);
        if(prev){
            prev->next = curr;
        }
        else{
            prev = curr;
            dummy_head->next = curr;
        }
        prev = curr;
    }
    return dummy_head->next;
}

void displayList(linkedList* head){
    linkedList* curr = head;
    while(curr){
        cout << curr->data << " " ;
        curr = curr->next;
    }
    cout << endl;
}



linkedList* getLastNodeinList(linkedList* head){
    linkedList* curr  = head;
    while(curr->next){
        curr =curr->next;
    }
    return curr;
}

void honorsTest(){
    /*
    cout << "###### Running minPositiveNum test ########### " << endl;
    vector<int> arr = {3, 5, 4, -1, 5, 1, -1};
    int minPositiveVal = findMinPositiveMissingNum1(arr);
    cout << " minPositiveNum is: " << minPositiveVal << endl;
    
    cout << "###### Running maxProductofAllButOne test ########### " << endl;
    int maxProductVal = maxProductMinusOne(arr);
    cout << "maxProductofAllButOne element is:" << maxProductVal << endl;
    
    vector<double> prices = {55.4, 57.3, 50.9, 44.45, 78.33, 22.44};
    double maxProfit = maxProfitFromStock(prices, 2);
    
    cout << "maxProfit for the price series is" << maxProfit << endl;
    
    vector<int> A = {2, 11, 3, 5, 13, 17, 19, 17, 23};
    pair<int, int> result = maxIncreasingSeqLen(A);
    
    cout << "maxIncreasing sequence is : {" << result.first << ", " << result.second << " }." << endl;
    
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    rotateArr(6, arr1);
    
    for(int a:arr1){
        cout << a << ", " ;
    }
    cout << endl;
    
    vector<vector<int>> positions(8, vector<int>(8,1));
    
    positions[0][1] =0, positions[3][5] =0, positions[4][3] =0, positions[6][0] =0;
    positions[6][5] = 0;
    
    cout << "current positions is " << endl;
    display2DArr(positions);
    updatePositionPossiblyAttackedByRook(positions);
    cout << "new positions are " << endl;
    display2DArr(positions);
    
    vector<string> words = {"The", "quick", "brown", "fox", "jumped", "over", "the", "lazy", "dogs."};
    vector<string> res = justifyText(words, 11);
    for(string line:res){
        cout << line << endl;
    }
     */
    linkedList* head = /* makeListFromArray({1,2,3}) ; */ makeListFromArray({2, 2, 3, 5, 7, 11, 11});
    displayList(head);
    head = reverseKList(head, 3);
    displayList(head);
    
    linkedList* nHead = makeListFromArray({1, 2, 3, 4, 5, 6, 7, 8, 9});
   /* displayList(nHead);
    nHead = zipLinkList(nHead);
    displayList(nHead);
    
    linkedList* lastNode = getLastNodeinList(nHead);
    lastNode->next = nHead;
    
    double medianVal = findMedianOfCircularLinkedList(lastNode);
    
    cout << "the median of circular list is: " << medianVal << endl;
    
    string parStr("((())()(()(");
    size_t maxLen = longestValidPara(parStr);
    cout << " maxLength of the para is: " << maxLen << endl;
    
    vector<trafficElement> trafficVol = {{0, 1.3}, {2, 2.5}, {3, 3.7}, {5, 1.4}, {6, 2.6}, {8, 2.2}, {9, 1.7}, {14, 1.7}};
    vector<trafficElement> maxVol = calculateTrafficeVolumes(trafficVol, 3);
    for(trafficElement elem: maxVol){
        cout <<  "{ " << elem.time << " ," << elem.volume << " }, " ;
    }
    cout << endl;
    
    unique_ptr<binaryNode<int>> node1 = new binaryNode<int>(14, nullptr, nullptr);
    
    vector<int> setLst({1, 2, 3, 4});
    vector<vector<int>> powrSet = getPowerSet(setLst);
    for(vector<int> subSet:powrSet){
        for(int elem: subSet){
            cout << elem << " ";
        }
        cout << endl;
    }
    
    vector<vector<double>> exchRates = {
        {1, 0.8123, 0.6404, 78.125, 0.9784, 0.9924, 0.9465},
        {1.2275, 1, 0.7860, 96.55, 1.2010, 1.2182, 1.1616},
        {1.5617, 1.2724, 1, 122.83, 1.5280, 1.5498, 1.4778},
        {0.0128, 0.0104, 0.0081, 1, 1.2442, 0.0126, 0.0120},
        {1.0219, 0.8327, 0.6546, 80.39, 1, 1.0142, 0.9672},
        {1.0076, 0.8206, 0.6453, 79.26, 0.9859, 1, 0.9535},
        {1.0567, 0.8609, 0.6767, 83.12, 1.0339, 1.0487, 1}
    };
    
    bool is_arbitragePossible = doesArbitrageExist(exchRates);
    
    cout << "is_arbitragePossible = " << is_arbitragePossible << endl;
    
    graphVertex* a = new graphVertex(0,0, {});
    graphVertex* b = new graphVertex(0,0, {});
    graphVertex* c = new graphVertex(0,0, {});
    graphVertex* d = new graphVertex(0,0, {});
    graphVertex* e = new graphVertex(0,0, {});
    graphVertex* f = new graphVertex(0,0, {});
    graphVertex* g = new graphVertex(0,0, {});
    graphVertex* h = new graphVertex(0,0, {});
    graphVertex* i = new graphVertex(0,0, {});
    graphVertex* j = new graphVertex(0,0, {});
    graphVertex* k = new graphVertex(0,0, {});
    graphVertex* l = new graphVertex(0,0, {});
    graphVertex* m = new graphVertex(0,0, {});
    
    
    a->edges = {b, c};
    
    b->edges = {d, e, a};
    c->edges = {a, d};
    d->edges = {b, c, e};
    e->edges = {b, d, f, h};
    f->edges = {e, g, i};
    g->edges = {f, h};
    h->edges = {e, g, i};
    i->edges = {h, f, m, j, l};
    j->edges = {i, k};
    k->edges = {l, m};
    l->edges = {i, k};
    m->edges = {i, k};
     
    
    vector<graphVertex*> graph = {a, b, c, d, e, f, g, h, i, j, k, l, m};
    bool isFaultTol = isGraphFaultTolerant(&graph);
    cout << "isGraphFault Tolerant = " << isFaultTol << endl;
    */
    
    vector<int> longSubArr = {431, -15, 639, 342, -14, 565, -924, 635, 167, -70};
    pair<int, int> subArrIndex = findLongestSubArrLessThanK(longSubArr, 184);
    
    cout << "long SubArry less than 184 is {" << subArrIndex.first << " , " << subArrIndex.second << "}" << endl;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    honorsTest();
    return 0;
}
