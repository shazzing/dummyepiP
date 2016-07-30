//
//  knapsackProblem.h
//  DSDynamicProgramming
//
//  Created by shashank hegde on 1/6/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef knapsackProblem_h
#define knapsackProblem_h
struct Item
{
    int weight, value;
};

int knapsackProblem(int w, const vector<Item>& items)
{
    vector<int> v(w+1, 0);
    for(int i=0; i< items.size(); i++)
    {
        for(int j=w; j>= items[i].weight; --j)
        {
            v[j] = max(v[j], v[j-items[i].weight] + items[i].value);
        }
    }
    return v[w];
}

#endif /* knapsackProblem_h */
