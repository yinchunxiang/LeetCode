/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/19 15:13:21
 * @brief 
 * 
 **/ 
 
int maxProfit(vector<int> &prices) {
    int buy = INT_MIN;
    int sell = 0;
    int cooldown = 0;
    for (int price : prices) {
        int prev_cooldown = cooldown;
        cooldown = max(cooldown, sell);
        int prev_sell = sell;
        sell = max(sell, buy + price);
        int prev_buy = buy;
        buy = max(buy, prev_cooldown - price);
    }
    return sell;

}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
