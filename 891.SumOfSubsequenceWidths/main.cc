class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int size = A.size();
        if (size < 2) return 0;
        std::sort(A.begin(), A.end());
        int sum = 0;
        int mod = 1e9 + 7;
        long c = 1;
        for (int i = 0; i < size; ++i, c = (c<<1) % mod) {
            // 在加的时候。int可能会溢出，所以需要long
            sum = (sum + A[i] * c - A[size - 1 - i] * c) % mod;
        }
        return (sum + mod) % mod;
    }
};
