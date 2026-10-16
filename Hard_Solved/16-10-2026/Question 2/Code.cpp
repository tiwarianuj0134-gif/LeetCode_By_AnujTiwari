#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
private:
    unordered_set<string> dict;
    vector<string> memo[21];
    bool computed[21] = {};
    string s;
    int n;

    const vector<string>& dfs(int start) {
        if (computed[start]) {
            return memo[start];
        }

        computed[start] = true;

        if (start == n) {
            memo[start].push_back("");
            return memo[start];
        }

        string word;
        word.reserve(10);

        for (int end = start; end < n && end - start < 10; ++end) {
            word.push_back(s[end]);

            if (dict.find(word) == dict.end()) {
                continue;
            }

            const auto& suffixes = dfs(end + 1);

            for (const string& suffix : suffixes) {
                if (suffix.empty()) {
                    memo[start].push_back(word);
                } else {
                    string sentence;
                    sentence.reserve(word.size() + 1 + suffix.size());
                    sentence += word;
                    sentence += ' ';
                    sentence += suffix;
                    memo[start].push_back(move(sentence));
                }
            }
        }

        return memo[start];
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = move(s);
        n = static_cast<int>(this->s.size());

        dict.clear();
        dict.reserve(wordDict.size() * 2);

        for (const string& word : wordDict) {
            dict.insert(word);
        }

        for (int i = 0; i <= n; ++i) {
            memo[i].clear();
            computed[i] = false;
        }

        return dfs(0);
    }
};
