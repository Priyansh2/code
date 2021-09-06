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

class NestedIterator {
    queue<int> st;
    void flatten(vector<NestedInteger> list){
        for(auto x : list){
            if(x.isInteger()) st.push(x.getInteger());
            else flatten(x.getList());
        }
    }
    stack<vector<NestedInteger>:: iterator> start,end;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        //flatten(nestedList);
        start.push(nestedList.begin());
        end.push(nestedList.end());
        
    }
    
    int next() {
        /*auto x = st.front();
        st.pop();
        return x;*/
        int x = start.top()->getInteger();
        start.top()++;
        return x;
    }
    
    bool hasNext() {
        //return !st.empty();
        while(!start.empty()){
            if(start.top()==end.top()){
                start.pop();
                end.pop(); 
            }
            else{
                
                auto x = start.top();
                if(x->isInteger()){
                    return true;
                }
                
                start.top()++;
                start.push(x->getList().begin());
                end.push(x->getList().end());
                
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */