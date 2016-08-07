//
//  justifyText.hpp
//  epi
//
//  Created by shashank hegde on 8/7/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef justifyText_h
#define justifyText_h
#include <string>
#include <vector>
#include <cmath>
using namespace std;


string createLineWithSpaces(const vector<string>& words, size_t start, size_t end, size_t num_spaces){
    string line;
    size_t num_words_curr_line = end - start + 1;
    for(size_t i=start; i<end; i++){
        line += words[i];
        num_words_curr_line--;
        size_t num_next_space = ceil(static_cast<double>(num_spaces/num_words_curr_line));
        line.append(num_next_space, ' ');
        num_spaces -= num_next_space;
    }
    line += words[end];
    line.append(num_spaces, ' '); // will handle the last line case where there will be spaces at end
    return line;
}

vector<string> justifyText(const vector<string>& words, int L){
    size_t curr_line_stIndex=0, num_words_curr_line =0, curr_line_length=0;
    vector<string> result;
    for(size_t i=0; i<words.size(); i++){
        ++num_words_curr_line;
        size_t lookahead_line_length = curr_line_length + (num_words_curr_line -1) /* for spaces */ + words[i].size();
        if(lookahead_line_length == L){
            result.emplace_back(createLineWithSpaces(words, curr_line_stIndex, i, i-curr_line_stIndex));
            curr_line_stIndex = i+1, num_words_curr_line=0, curr_line_length=0;
        }
        else if(lookahead_line_length > L){
            result.emplace_back(createLineWithSpaces(words, curr_line_stIndex, i-1, L-curr_line_length));
            curr_line_stIndex =i, num_words_curr_line=1, curr_line_length = words[i].size();
        }
        else{ //lookahead_line_length < L
            curr_line_length += words[i].size();
        }
    }
    // last line
    if(num_words_curr_line>0){
        string line  = createLineWithSpaces(words, curr_line_stIndex, words.size()-1, num_words_curr_line-1);
        line.append(L-(num_words_curr_line-1) - curr_line_length, ' ');
        result.emplace_back(line);
    }
    return result;
}


#endif /* justifyText_h */
