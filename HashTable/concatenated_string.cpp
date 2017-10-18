class Solution {
public:
    /*
     * @param : the 1st string
     * @param : the 2nd string
     * @return: uncommon characters of given strings
     */
    string concatenetedString(string &s1, string &s2) {
    	string s = s1 + s2;
    	string new_str;//空字符串
        char hash_table[26] = {0};
        unsigned int i = 0, addr = 0;
        for(i=0;i<s1.size();i++)//将s1存入哈希表
        {
        	addr = s1[i] - 97;//哈希函数
        	if(hash_table[addr]!=0)//有冲突
        	{
        		continue;
        	}
        	hash_table[addr] = 1;
        }
        for(i=0;i<s2.size();i++)
        {
        	addr = s2[i] - 97;
        	if(hash_table[addr]==1||hash_table[addr]==-1)
        	{
        		hash_table[addr] = -1;
        		continue;
        	}
        	if(hash_table[addr]==2)
        	{
        		continue;
        	}
        	hash_table[addr] = 2;
        }
        for(i=0;i<s.size();i++)
        {
        	addr = s[i] - 97;
        	if(hash_table[addr]==-1)
        		continue;
        	new_str = new_str + s[i];
        }
        return new_str;
    }
};