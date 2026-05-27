class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto it: s)
        {
            if(it=='(' or it =='[' or it=='{')
            {
                stk.push(it);
            }
            else if(it==')')
            {
                if(!stk.empty() and stk.top()=='(')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(it==']')
            {
                if(!stk.empty() and stk.top()=='[')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(it=='}')
            {
                if(!stk.empty() and stk.top()=='{')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {

            }
        }
        if(stk.empty())
        {
            return true;
        }
        return false;
    }
};
