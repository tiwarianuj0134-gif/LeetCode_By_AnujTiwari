class Solution {
public:
    vector<int> grayCode(int n) {
        int total = 1 << n;

        vector<int> ans;
        ans.reserve(total);

        for (int i = 0; i < total; i++) {
            ans.push_back(i ^ (i >> 1));
        }

        return ans;
    }
};
