 class Solution {
public:
    /*
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string s) {
        map<char,unsigned int> hash_table;
        unsigned int length = 0;
        bool mid_flag = false;
        for(auto ch : s)
        	hash_table[ch]++;
        for(auto it : hash_table)
        {
        	length += it.second;
        	if(it.second%2==1)
        	{
        		length--;
        		mid_flag = true;
        	}
        }
        length += mid_flag?1:0;
        return length;
    }
};

/*solution 2*/
 class Solution {
public:
    /*
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string s) {
        set<char> t;
        for(auto ch : s)
        {
        	if(t.find(ch)==t.end())
        		t.insert(ch);
        	else
        		t.erase(ch);
        }
        return (s.size()-max(0,(int)t.size()-1));
    }
};