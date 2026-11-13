class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l1 = s1.size(), l2 = s2.size();

        vector<int> seen(l2, -1);
        vector<int> count(l2, 0);

        int j = 0;
        int cnt = 0;

        for (int i = 1; i <= n1; ++i) {
            for (char c : s1) {
                if (c == s2[j]) {
                    ++j;

                    if (j == l2) {
                        j = 0;
                        ++cnt;
                    }
                }
            }

            if (seen[j] != -1) {
                int prevI = seen[j];
                int prevCnt = count[j];

                int cycleLen = i - prevI;
                int cycleCnt = cnt - prevCnt;

                int remaining = n1 - i;
                int cycles = remaining / cycleLen;

                cnt += cycles * cycleCnt;
                i += cycles * cycleLen;
            } else {
                seen[j] = i;
                count[j] = cnt;
            }
        }

        return cnt / n2;
    }
};
