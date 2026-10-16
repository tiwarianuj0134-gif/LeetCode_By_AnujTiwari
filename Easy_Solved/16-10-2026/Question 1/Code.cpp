#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left < right) {
            while (left < right &&
                   !isAlphanumeric(s[left])) {
                ++left;
            }

            while (left < right &&
                   !isAlphanumeric(s[right])) {
                --right;
            }

            if (toLower(s[left]) != toLower(s[right])) {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }

private:
    static bool isAlphanumeric(char c) {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9');
    }

    static char toLower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A');
        }
        return c;
    }
};
