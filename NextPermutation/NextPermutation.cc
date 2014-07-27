    int find_peak(const vector<int>& num) {
        int ret = 0;
        for(int i = num.size() - 1, j = i -1; i>=0 && j>=0; i--,j--) {
            if (num[j] < num[i]) {
                ret = i;
                break;
            }
        }
        return ret;
    }
    void nextPermutation(vector<int> &num) {
        int vec_size = num.size();
        if (vec_size <= 1) {
            return;
        }
        int peak = find_peak(num);
        if (0 >= peak) {
            sort(num.begin(), num.end());
            return;
        }
        
        if (peak == vec_size - 1) {
            swap(num[peak - 1], num[peak]);
            return;
        }
        
        
        for(int i = vec_size - 1; i >= peak; i--) {
            if (num[i] > num[peak - 1]){
                swap(num[peak - i], num[i]);        
            }
        }
        
        sort(num.begin() + peak, num.end());
    }
