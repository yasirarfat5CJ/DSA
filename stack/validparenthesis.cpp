class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }else{
                if(st.size()==0){
                    return false;
                }
            if ((st.top() == '(' && s[i] == ')') ||
             (st.top() == '[' && s[i] == ']') ||
             (st.top() == '{' && s[i] == '}')) {
                st.pop();
                } else {
                     return false;
            }
        }

     }
        return st.size()==0;
        
          
    }
};

/* In this problem we have to find the given parenthesis is  valid or not 
Approach:the approach behind this problem is whenever we find any open parenthesis we  push it into the stack
else if the  stack is empty we  return false  again we find the  matching closing parenthsis if found we pop it from stack 
at last we check if the stack  is empty we return true else false
*/