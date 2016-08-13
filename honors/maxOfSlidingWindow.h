//
//  maxOfSlidingWindow.h
//  epi
//
//  Created by shashank hegde on 8/13/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef maxOfSlidingWindow_h
#define maxOfSlidingWindow_h
#include <vector>
#include <queue>
using namespace std;

struct trafficElement{
    bool operator<(const trafficElement& that){
        return volume < that.volume;
    }
    
    bool operator==(const trafficElement& that){
        return volume == that.volume && time == that.time;
    }
    
    trafficElement(long time, double volume):volume(volume), time(time){
    }
    
    long time;
    double volume;
};

template <typename T>
class queueWithMax{
public:
    void Enqueue(T data){
        entries.emplace(data);
        while(!candiates_for_max_.empty()){
            if(data < candiates_for_max_.back())
                break;
            candiates_for_max_.pop_back();
        }
        candiates_for_max_.emplace_back(data);
    }
    
    T Dequeue(){
        if(!entries.empty()){
            T result = entries.front();
            if(result == candiates_for_max_.front()){
                candiates_for_max_.pop_front();
            }
            entries.pop();
            return result;
        }
        else{
            throw length_error("empty_queue");
        }
    }
    
    bool isEmpty(){
        return entries.empty();
    }
    
    T max(){
        if(!candiates_for_max_.empty()){
            return candiates_for_max_.front();
        }
        else{
            throw length_error("empty max queue");
        }
    }
    
    T front(){
        if(!entries.empty()){
            return entries.front();
        }
        else{
            throw length_error("empty queue");
        }
    }
    
private:
    queue<T> entries;
    deque<T> candiates_for_max_;
};


vector<trafficElement> calculateTrafficeVolumes(const vector<trafficElement>& volTraffic, long w){
    queueWithMax<trafficElement> slidingWindow;
    vector<trafficElement> maxVolForW;
    for(const trafficElement& elem: volTraffic){
        // populate all time intervals b/w prev int and curr trafficVolume
        long lastInsertedTime = maxVolForW.empty() ? 0 : maxVolForW.back().time+1;
        for(long i=lastInsertedTime; i <= elem.time; i++){
            if(i==elem.time){
              slidingWindow.Enqueue(elem);  
            }
            while(!slidingWindow.isEmpty() && (i - slidingWindow.front().time > w)){
                slidingWindow.Dequeue();
            }
            
            maxVolForW.emplace_back(trafficElement{i, slidingWindow.isEmpty() ? 0 : slidingWindow.max().volume});
        }
        
        }
    
    
    return maxVolForW;
}


#endif /* maxOfSlidingWindow_h */
