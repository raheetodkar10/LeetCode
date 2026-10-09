class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median;

    MedianFinder() {   //TC:O(log n), SC:O(n)
        median = 0;
    }
    
    void addNum(int num) {   //we're interested in just mid elem, not in other elem. & sorting will increase TC ie. n (log n)
        if(maxHeap.size() == minHeap.size()){
            if(num > median){
                //insert at right
                minHeap.push(num);
                median = minHeap.top();
            }
            else{
                //insert at left
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
        else if(maxHeap.size() == minHeap.size() + 1){
            //maxHeap ka size bada he as compared to minHeap by 1
            if(num > median){
                //insert at right
                minHeap.push(num);
                median = (minHeap.top() + maxHeap.top()) / 2.0;
            }
            else{
                //insert in left
                //maxHeap already bada he so directly insert nai kr sakte, toh 1 elem remove from maxHeap and insert in minHeap
                int elem = maxHeap.top();
                maxHeap.pop();
                minHeap.push(elem);
                //now insert num in left
                maxHeap.push(num);
                median = (minHeap.top()+maxHeap.top())/2.0;
            }
        }
        else if(maxHeap.size() + 1 == minHeap.size()){
            if(num > median){
                //insert in right
                //minHeap already bada he so directly insert nai kr sakte, toh 1 elem remove from minHeap and insert in maxHeap
                int elem = minHeap.top();
                minHeap.pop();
                maxHeap.push(elem);
                //now insert num in right
                minHeap.push(num);
                median = (minHeap.top() + maxHeap.top()) / 2.0;
            }
            else{
                //insert at left
                maxHeap.push(num);
                median = (minHeap.top() + maxHeap.top()) / 2.0;
            }
           
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */