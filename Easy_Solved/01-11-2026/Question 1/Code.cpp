class MyQueue {
private:
    stack<int> input, output;

    void transfer() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        input.push(x);
    }

    int pop() {
        transfer();

        int front = output.top();
        output.pop();

        return front;
    }

    int peek() {
        transfer();
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};
