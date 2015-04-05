class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }
    stack<int> stk;
    stack<int> stk_min;
    void push(int number) {
        stk.push(number);
        if (stk_min.empty()){
            stk_min.push(number);
        }else{
            int min = stk_min.top();
            if(number < min){
                stk_min.push(number);
            }else{
                stk_min.push(min);
            }
        }
    }

    int pop() {
        int result = stk.top();
        stk.pop();
        stk_min.pop();
        return result;
    }
    
    int min() {
        return stk_min.top();
    }
};

