/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/04 16:37:00
 * @brief 
 * 
 **/ 
 
ass Solution {
    public:
        string removeDuplicateLetters(string s) {
            vector<int> counts(26, 0);
            for (auto &ch : s) {
                int index = ch - 'a'
                counts[index] += 1;
            }
                    
                
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
