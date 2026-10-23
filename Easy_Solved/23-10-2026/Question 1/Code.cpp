class Solution {
public:
    int reverseBits(int n) {
        uint32_t x = static_cast<uint32_t>(n);
        uint32_t rev = 0;

        for (int i = 0; i < 32; ++i) {
            rev = (rev << 1) | (x & 1u);
            x >>= 1;
        }

        return static_cast<int>(rev);
    }
};
