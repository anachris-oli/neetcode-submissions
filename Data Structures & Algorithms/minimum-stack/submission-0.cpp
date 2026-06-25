class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        data_.push_back(val);
    }
    
    void pop() {
        
        data_.pop_back();
    }
    
    int top() {
        return data_.back();
    }
    
    int getMin() {
        auto it_min = min_element(data_.begin(),data_.end());
        return *it_min;
    }

private:
    vector<int> data_;
};
