class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];  //hr ek car ko pakda
            if(ch=='(' || ch=='{' || ch=='['){
                //open bracket: insert
                st.push(ch);
            }
            else{
                //for closing bracket:
                //pre-check : if stack is empty
                if(st.empty()){
                    //no empty
                    return false;
                }
                if(ch==')' && st.top()!='('){
                    //no match
                    return false;
                }
                else if(ch=='}' && st.top()!='{'){
                    return false;
                }
                else if(ch==']' && st.top()!='['){
                    return false;
                }
                else{
                    //match case
                    st.pop();
                }
            }
        }
        //here we can make mistake (true false pn lihu shakto instead of st.empty())
        /*if(s.empty()){
            //mtlb sare brackets cancel out hogya he successfully
            return true;
        }
        else{
            //cancel out hogye he but still smthng is left in stack
            return false;
        }*/
        return st.empty();   //means empty hoga to true return hoga varna false
    }
};