class Solution {
public:    //linear tc
    //combination of next and smaller element
    void nextSmaller(vector<int>& heights, vector<int>& nextAns){
        stack<int>st;
        st.push(-1);
        int n=heights.size();
        for(int i=n-1;i>=0;i--){
            int elem = heights[i];
            while(st.top()!=-1 && heights[st.top()] >= elem){    //ethe s.top() he ek index ahe
                st.pop();
            }
            //jevha me ethe pohochle, mtlb, ya to koi chota number stack top pe he, ya fir -1 stack top pr he
            nextAns.push_back(st.top());
            //current number ko stack me push karna he
            st.push(i);
        }
    }

    void prevSmaller(vector<int>& heights, vector<int>& prevAns){
        stack<int>st;
        st.push(-1);
        int n=heights.size();
        for(int i=0;i<n;i++){
            int elem = heights[i];
            while(st.top()!=-1 && heights[st.top()] >= elem){    //s.top() is an index and heights[-1] is not right so st.top()!=-1
                st.pop();
            }
            //jevha me ethe pohochle, mtlb, ya to koi chota number stack top pe he, ya fir -1 stack top pr he
            prevAns.push_back(st.top());
            //current number ko stack me push karna he
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextAns;
        vector<int> prevAns;
        nextSmaller(heights,nextAns);
        reverse(nextAns.begin(),nextAns.end());
        //this is imp and me bhul jati hu
        for(int i=0;i<nextAns.size();i++){
            if(nextAns[i] == -1){   //If there is no smaller element on the right, it means the rectangle can extend all the way to end of histogram. So instead of -1, we use nextAns.size() which is the index just after last element. Means jithe -1 yeto tithe nextAns.size() chi value ghayaychi that will make it easy to find nextAns[i]-prevAns[i]-1
                nextAns[i] = nextAns.size();
            }
        }
        prevSmaller(heights,prevAns);     

        //vector<int> area;
        int maxArea = INT_MIN;
        for(int i=0;i<nextAns.size();i++){
            int width = nextAns[i]-prevAns[i]-1;
            int height = heights[i];
            int currArea = width * height;
            maxArea = max(maxArea,currArea);
        }
        return maxArea;
    }
};