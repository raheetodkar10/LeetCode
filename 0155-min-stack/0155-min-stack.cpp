class MinStack {
public: 
    //we'll use pairs(element, min element till now from bottom)
    vector<pair<int,int>> v;
    MinStack() { //constructor
        
    }
    
    void push(int value) {   //O(n)
        if(v.empty()){
            v.push_back({value,value});
            return;
        }
        //more than 1 elem
        auto top = v.back();      //v.back: latest elem that is pushed (ie the last elem in array)
        int min_till_now = min(value,top.second);   //apn pair store karaloy, so pair mdhla 2nd elem will be minimum so compared with it
        v.push_back({value,min_till_now});
    }
    
    void pop() {   //O(n)
        v.pop_back();
    }
    
    int top() {    //O(n)
        return v.back().first;
    }
    
    int getMin() {   //O(n)
        return v.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */