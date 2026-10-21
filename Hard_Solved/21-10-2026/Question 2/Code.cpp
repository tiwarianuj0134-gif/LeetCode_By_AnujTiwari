class Solution {
public:
    int calculate(string s) {
        long long result = 0, number = 0;
        int sign = 1;
        long long stack[300005];
        int top = 0;

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                number = number * 10 + (c - '0');
            } 
            else if (c == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } 
            else if (c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } 
            else if (c == '(') {
                stack[top++] = result;
                stack[top++] = sign;
                result = 0;
                sign = 1;
            } 
            else if (c == ')') {
                result += sign * number;
                number = 0;
                result *= stack[--top];
                result += stack[--top];
            }
        }

        result += sign * number;
        return static_cast<int>(result);
    }
};
