class Solution {
public:
    /*
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
    	unsigned int i = 0;
    	stack<char> sk;
    	for(i=0;i<s.size();i++)
    	{
    		if(s[i]=='('||s[i]=='['||s[i]=='{')
    			sk.push(s[i]);
    		else
    		{
    			if(sk.empty())
    				return false;
    			char top = sk.top();
    			if(s[i]==')'&&top!='(')
    				return false;
    			if(s[i]==']'&&top!='[')
    				return false;
    			if(s[i]=='}'&&top!='{')
    				return false;
    			sk.pop();
    		}
    	}
    	if(!sk.empty())
    		return false;
    	return true;
    }
};