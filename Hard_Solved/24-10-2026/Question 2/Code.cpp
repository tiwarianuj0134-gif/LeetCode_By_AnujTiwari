
class Solution {
    vector<string> ans;
    string expr;
    string num;
    long long target;
    int n;

    void dfs(int pos, long long value, long long last) {
        if (pos == n) {
            if (value == target)
                ans.push_back(expr);
            return;
        }

        long long cur = 0;
        int oldSize = expr.size();

        for (int i = pos; i < n; ++i) {
            if (i > pos && num[pos] == '0')
                break;

            cur = cur * 10 + (num[i] - '0');
            int len = i - pos + 1;

            if (pos == 0) {
                expr.append(num, pos, len);
                dfs(i + 1, cur, cur);
                expr.resize(oldSize);
            } else {
                expr.push_back('+');
                expr.append(num, pos, len);
                dfs(i + 1, value + cur, cur);
                expr.resize(oldSize);

                expr.push_back('-');
                expr.append(num, pos, len);
                dfs(i + 1, value - cur, -cur);
                expr.resize(oldSize);

                expr.push_back('*');
                expr.append(num, pos, len);
                dfs(i + 1, value - last + last * cur,
                    last * cur);
                expr.resize(oldSize);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        this->num = std::move(num);
        this->target = target;
        n = this->num.size();

        ans.clear();
        expr.clear();
        expr.reserve(2 * n);

        dfs(0, 0, 0);
        return ans;
    }
};
