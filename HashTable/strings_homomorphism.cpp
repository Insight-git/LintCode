class Solution {
public:
    /*
     * @param s: a string
     * @param t: a string
     * @return: true if the characters in s can be replaced to get t or false
     */
    bool isIsomorphic(string s, string t) {
    	unsigned int i = 0;
        if(s.size()!=t.size())
        	return false;
        map<char,char> m;
        //建立s到t的映射
        for(i=0;i<s.size();i++)
        {
        	if(m.find(s[i])==m.end())
        		m[s[i]] = t[i];
        	else if(m[s[i]]!=t[i])
        		return false;
        }
        m.clear();
        //建立t到s的映射
        for(i=0;i<t.size();i++)
        {
        	if(m.find([t[i]])==m.end())
        		m[t[i]] = s[i];
        	else if(m[t[i]]!=s[i])
        		return false;
        }
        return true;
    }
};

/*solution 2*/
class Solution {
public:
    /*
     * @param s: a string
     * @param t: a string
     * @return: true if the characters in s can be replaced to get t or false
     */
    bool isIsomorphic(string s, string t) {
    	map<char,size_type> sm;
    	map<char,size_type> tm;
    	unsigned int i = 0;
    	if(s.size()!=t.size())
    		return false;
    	for(i=0;i<s.size();i++)
    	{
    		sm.insert(pair<char,size_type> (s[i],i));
    		tm.insert(pair<char,size_type> (t[i],i));
    	}
    	unsigned int *index_s = new unsigned int[s.size()];
    	unsigned int *index_t = new unsigned int[t.size()];
    	for(i=0;i<s.size();i++)
    	{
    		index_s[i] = sm.find(s[i])->second;
    		index_t[i] = tm.find(t[i])->second;
    	}
    	for(i=0;i<s.size();i++)
    	{
    		if(index_s[i]!=index_t[i])
    			return false;
    	}
    	return true;
    }
};
/*solution 3*/
class Solution {
public:
    /*
     * @param s: a string
     * @param t: a string
     * @return: true if the characters in s can be replaced to get t or false
     */
    bool isIsomorphic(string s, string t) {
    	unsigned int i = 0;
        if(s.size()!=t.size())
        	return false;
        map<char,char> hash_map;
        set<char> hash_set;
        //建立映射
        for(i=0;i<s.size();i++)
        {
        	if(hash_map.find(s[i])==hash_map.end())
        	{
        		if(hash_set.find(t[i])!=hash_set.end())//存在重复映射
        			return false;
        		hash_map[s[i]] = t[i];
        		hash_set.insert(t[i]);
        	}
        	else if(hash_map[s[i]]!=t[i])
        		return false;
        }
        return true;
    }
};