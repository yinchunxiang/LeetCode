//
// Created by yinchunxiang on 23/01/2018.
//

#include <vector>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int size = (int)row.size();
        // 位置i的partner的位置
        vector<int> partner(size, 0);
        vector<int> position(size, 0);
        for (int i = 0; i < size; ++i) {
            partner[i] = (i ^ 1) == 0 ? i + 1 : i - 1;
            position[row[i]] = i;
        }

        int count = 0;
        for (int i = 0; i < size; ++i) {
            // 判断i应该在的位置和当前位置是否相同
            for (int j = partner[position[partner[row[i]]]];
                 i != j;
                 j = partner[position[partner[row[i]]]]
            ) {
                swap(row[i], row[j]);
                swap(position[row[i]], position[row[j]]);
                count ++;
            }
        }
        return count;

    }
};