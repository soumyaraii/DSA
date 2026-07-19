class MyStack {
    queue<int> ip;
    queue<int> op;

public:
    MyStack() {
    }

    void push(int x) {
        ip.push(x);
    }

    int pop() {
        while (ip.size() > 1) {
            op.push(ip.front());
            ip.pop();
        }

        int temp = ip.front();
        ip.pop();

        swap(ip, op);

        return temp;
    }

    int top() {
        while (ip.size() > 1) {
            op.push(ip.front());
            ip.pop();
        }

        int temp = ip.front();

        // Don't remove it permanently
        op.push(ip.front());
        ip.pop();

        swap(ip, op);

        return temp;
    }

    bool empty() {
        return ip.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */