class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string res;
        res.reserve(n);

        int dirs[1501];
        int top = 0;

        for (int i = 0; i < n;) {
            while (i < n && path[i] == '/') ++i;
            if (i == n) break;

            int start = i;
            while (i < n && path[i] != '/') ++i;

            int len = i - start;

            if (len == 1 && path[start] == '.') continue;

            if (len == 2 && path[start] == '.' &&
                path[start + 1] == '.') {
                if (top) {
                    res.resize(dirs[--top]);
                }
                continue;
            }

            dirs[top++] = res.size();
            res += '/';
            res.append(path, start, len);
        }

        if (res.empty()) return "/";
        return res;
    }
};