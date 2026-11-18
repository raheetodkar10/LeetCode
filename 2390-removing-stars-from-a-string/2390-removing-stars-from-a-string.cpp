class Solution {
public:
    string removeStars(string s) {  //TC:O(n) , SC:O(1)
        //non star->push in stak, if *-> stack chya top cha elem pop, final string stack mde insert kelya mule ulti asnar tila reverse karaych
        string ans = "";
        for(char ch : s){
            if(ch == '*'){    //use single quotation '' for char
                ans.pop_back();
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
/* stack<char> st;
        for(char ch : s){
            if(ch == '*'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(ch);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;   */