class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();

        int lower = 0, upper = 0, digit = 0;
        vector<int> runs;

        for (char c : password) {
            if (c >= 'a' && c <= 'z') lower = 1;
            else if (c >= 'A' && c <= 'Z') upper = 1;
            else if (c >= '0' && c <= '9') digit = 1;
        }

        int missing = 3 - (lower + upper + digit);

        for (int i = 0; i < n;) {
            int j = i;

            while (j < n && password[j] == password[i])
                ++j;

            if (j - i >= 3)
                runs.push_back(j - i);

            i = j;
        }

        if (n < 6) {
            return max(missing, 6 - n);
        }

        int replacements = 0;

        for (int len : runs)
            replacements += len / 3;

        if (n <= 20)
            return max(missing, replacements);

        int deletions = n - 20;
        int remaining = deletions;

        for (int i = 0; i < runs.size() && remaining > 0; ++i) {
            if (runs[i] % 3 == 0) {
                int use = min(remaining, 1);
                runs[i] -= use;
                remaining -= use;
            }
        }

        for (int i = 0; i < runs.size() && remaining > 0; ++i) {
            if (runs[i] % 3 == 1) {
                int use = min(remaining, 2);
                runs[i] -= use;
                remaining -= use;
            }
        }

        for (int i = 0; i < runs.size() && remaining > 0; ++i) {
            int use = min(remaining, runs[i] - 2);
            runs[i] -= use;
            remaining -= use;
        }

        replacements = 0;

        for (int len : runs)
            replacements += len / 3;

        return deletions + max(missing, replacements);
    }
};
