/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {   //O(n)  (har elem ko ek baar hi visit kr rahe he)
    queue<int> flattenQ;

    void flatten(vector<NestedInteger> &nestedList){  //ethe vector chya jagi list pn lihu shakto
        for(auto item:nestedList){
            if(item.isInteger()){
                //for now, item is object is nestedInteger class
                flattenQ.push(item.getInteger());
            }
            else{   //we encountered a list in vector
                flatten(item.getList());   //Recursion call (mhanje jr lost asel tr parat loop run honar for each elem in list)
            }
        }
    }
public:
    //ctor
    NestedIterator(vector<NestedInteger> &nestedList) { //flatten->thoda low level design yeta
        flatten(nestedList);
    }
    
    int next() {
        int front = flattenQ.front();
        flattenQ.pop();  //jevha next() call honar tevha Q chya front mdhun pop krun dyaych  (down)
        return front;  
    }
    
    bool hasNext() {
        return !flattenQ.empty();  //nested list mde kay nasel tr return false
        //jb Q empty nai hogi, statm will return false
    }
    
    /*Suppose after flattening: flattenQ = [1, 2, 3, 4, 5]
    When you call: next();
    First:  int front = flattenQ.front();
    front becomes:  front = 1
    Queue is still: [1, 2, 3, 4, 5]
    Then: flattenQ.pop();
    removes 1: [2, 3, 4, 5]
    Finally: return front;
    returns: 1 */
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */