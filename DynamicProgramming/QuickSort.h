//
//  QuickSort.h
//  DSDynamicProgramming
//
//  Created by shashank hegde on 1/3/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef QuickSort_h
#define QuickSort_h
#include <vector>

using namespace std;


int partition (vector<int>& arr, int left, int right)
{
    int x = arr[right]; // Make the last element the pivot.
    int i = (left - 1);
    
    for (int j = left; j <= right- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void quicksort(vector<int>& arr, int left, int right){
    if(left < right)
    {
        int pivot = partition(arr, left, right);
        quicksort(arr, left, pivot-1);
        quicksort(arr,pivot+1,right);
    }
}


#endif /* QuickSort_h */
