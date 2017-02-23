/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file best_solution.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/22 23:27:43
 * @brief 
 * 
 **/ 
 
bool isSubsequence(char* s, char* t) {
    while (*t) {
        s += *s == *t++;
    }
    return !*s;

}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
