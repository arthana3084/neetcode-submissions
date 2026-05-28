class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+")
            {
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                int c=a+b;
                st.push(c);
            }
            else if(tokens[i]=="-")
            {
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                int c=a-b;
                st.push(c);
            }
            else if(tokens[i]=="*")
            {
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                int c=a*b;
                st.push(c);
            }
            else if(tokens[i]=="/")
            {
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                int c=a/b;
                st.push(c);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
