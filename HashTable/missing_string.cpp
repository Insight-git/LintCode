/*solution 1 哈希表*/
class Solution {
public:
    /*
     * @param : a given string
     * @param : another given string
     * @return: An array of missing string
     */
    vector<string> SplitWords(string str)
    {
        stringstream stream(str);
        vector<string> words;
        string temp;
        while(stream >> temp)   //字符流,分词
            words.push_back(temp);
        return words;
    }
    /* solution 2 split word
    vector<string> SplitWords(string str)
    {
        vector<string> words;
        unsigned int i = 0;
        string temp;
        for(i=0;i<str.size();i++)//分词
        {
            if(str[i]==' ')
            {
                words.push_back(temp);
                temp.clear();
                i++;
                while(str[i]==' ')
                    i++;
            }
            temp += str[i];
        }
        words.push_back(temp);
        return words;
    }
    */
    void CreateHashTable(vector<string> words,string *hash_table)
    {
        int i = 0, j = 0;
        unsigned int addr = 0;
        string temp;
        for(i=0;i<words.size();i++)//将单词存入哈希表
        {
            temp = words[i];
            unsigned int key = 0;
            for(j=0;j<temp.size();j++)
            {
                key += temp[j];//求关键字
            }
            addr = key % words.size();//哈希函数算地址
            while(hash_table[addr]!="")//地址有冲突
            {
                addr = (addr + 1) % words.size();//开放定址法线性探测
            }
            hash_table[addr] = temp;
        }
    }
    bool SearchWord(string *hash_table, string word, unsigned int hash_table_size)
    {
        unsigned int addr = 0;
        unsigned int key = 0, j = 0;
        for(j=0;j<word.size();j++)//算键值
        {
            key += word[j];
        }
        addr = key % hash_table_size;//哈希函数算地址
        while(hash_table[addr]!=word)
        {
            addr = (addr + 1) % hash_table_size;//开放定址法线性探测
            if(addr==key%hash_table_size||hash_table[addr]=="")
            {
                return false;
            }
        }
        return true;
    }
    vector<string> missingString(string str1, string str2) {
        vector<string> result;
        string *hash_table = NULL;
        vector<string> words1, words2;
        unsigned int i = 0;
        words1 = SplitWords(str1);
        words2 = SplitWords(str2);
    	if(words2.size()>words1.size())
    	{
	    	vector<string> vect_temp = words2;
	    	words2 = words1;
	    	words1 = vect_temp;
	    }
        hash_table = new string[words2.size()];
	    CreateHashTable(words2,hash_table);
    	for(i=0;i<words1.size();i++)//长的字符串与哈希表中的字符串匹配，如果匹配不成功，则判断是缺少的字符串
    	{
            if(words2.size()==0)
            {
                result.push_back(words1[i]);
            }
    		else 
            {
                if(!SearchWord(hash_table,words1[i],words2.size()))
                    result.push_back(words1[i]);
            }
    	}
    	delete [] hash_table;
        return result;
    }
};

/*solution 2 vector查找*/
class Solution {
public:
    /*
     * @param : a given string
     * @param : another given string
     * @return: An array of missing string
     */
    vector<string> SplitWords(string str)
    {
        stringstream stream(str);
        vector<string> words;
        string temp;
        while(stream >> temp)   //字符流,分词
            words.push_back(temp);
        return words;
    }
    vector<string> missingString(string str1, string str2) {
        // Write your code here
        vector<string> words1;
        vector<string> words2;
        vector<string> result;
        unsigned int i = 0;

        words1 = SplitWords(str1);
        words2 = SplitWords(str2);
        for (int i = 0; i < words1.size(); i++) 
        {
            auto it = words2.end();
            it = find(words2.begin(), words2.end(), words1[i]);
            if (it == words2.end()) 
            {
                result.push_back(words1[i]);
            }
        }
        return result;
    }
};