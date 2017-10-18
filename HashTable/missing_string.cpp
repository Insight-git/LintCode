class Solution {
public:
    /*
     * @param : a given string
     * @param : another given string
     * @return: An array of missing string
     */
    vector<string> missingString(string str1, string str2) {
        vector<string> result;
        string *hash_table = NULL;
        vector<string> string1, string2;
        string temp;
        unsigned int i = 0, j = 0, addr = 0;
        stringstream ss1(str1); //字符流,分词
        while (ss1 >> temp) 
        {
            string1.push_back(temp);
        }
       	stringstream ss2(str2);
       	while (ss2 >> temp) 
       	{
            string2.push_back(temp);
        }
    	if(string2.size()>string1.size())
    	{
	    	vector<string> vect_temp = string2;
	    	string2 = string1;
	    	string1 = vect_temp;
	    }
	    hash_table = new string[string2.size()];
    	for(i=0;i<string2.size();i++)//将短的字符串存入哈希表中
    	{
    		temp = string2[i];
    		unsigned int key = 0;
    		for(j=0;j<temp.size();j++)
    		{
    			key += temp[j];//求关键字
    		}
    		addr = key % string2.size();//哈希函数算地址
    		while(hash_table[addr]!="")//地址有冲突
    		{
    			addr = (addr + 1) % string2.size();//开放定址法线性探测
    		}
    		hash_table[addr] = temp;
    	}
    	for(i=0;i<string1.size();i++)//长的字符串与哈希表中的字符串匹配，如果匹配不成功，则判断是缺少的字符串
    	{
    		temp = string1[i];
    		if(string2.size()==0)
    		{
    			result.push_back(temp);
    		}
    		else
    		{
        		unsigned int key = 0;
        		for(j=0;j<temp.size();j++)
        		{
        			key += temp[j];
        		}
        		addr = key % string2.size();
        		while(hash_table[addr]!=temp)
        		{
        			addr = (addr + 1) % string2.size();
        			if(addr==key%string2.size()||hash_table[addr]=="")
        			{
        				result.push_back(temp);
        				break;
        			}
        		}
        	}
    	}
    	delete [] hash_table;
        return result;
    }
};

class Solution {
public:
    /*
     * @param : a given string
     * @param : another given string
     * @return: An array of missing string
     */
    vector<string> missingString(string str1, string str2) {
        vector<string> result;
        string *hash_table = NULL;
        vector<string> string1, string2;
        string temp;
        unsigned int i = 0, j = 0, addr = 0;
        for(i=0;i<str1.size();i++)//分词
        {
        	if(str1[i]==' ')
        	{
        		string1.push_back(temp);
        		temp.clear();
        		i++;
        		while(str1[i]==' ')
        			i++;
        	}
        	temp += str1[i];
        }
        string1.push_back(temp);
        temp.clear();
        for(i=0;i<str2.size();i++)
        {
        	if(str2[i]==' ')
        	{
        		string2.push_back(temp);
        		temp.clear();
        		i++;
        		while(str2[i]==' ')
        			i++;
        	}
        	temp += str2[i];
        }
        string2.push_back(temp);
        temp.clear();
    	if(string2.size()>string1.size())
    	{
	    	vector<string> vect_temp = string2;
	    	string2 = string1;
	    	string1 = vect_temp;
	    }
	    hash_table = new string[string2.size()];
    	for(i=0;i<string2.size();i++)//将短的字符串存入哈希表中
    	{
    		temp = string2[i];
    		unsigned int key = 0;
    		for(j=0;j<temp.size();j++)
    		{
    			key += temp[j];//求关键字
    		}
    		addr = key % string2.size();//哈希函数算地址
    		while(hash_table[addr]!="")//地址有冲突
    		{
    			addr = (addr + 1) % string2.size();//开放定址法线性探测
    		}
    		hash_table[addr] = temp;
    	}
    	for(i=0;i<string1.size();i++)//长的字符串与哈希表中的字符串匹配，如果匹配不成功，则判断是缺少的字符串
    	{
    		temp = string1[i];
    		if(string2.size()==0)
    		{
    			result.push_back(temp);
    		}
    		else
    		{
        		unsigned int key = 0;
        		for(j=0;j<temp.size();j++)
        		{
        			key += temp[j];
        		}
        		addr = key % string2.size();
        		while(hash_table[addr]!=temp)
        		{
        			addr = (addr + 1) % string2.size();
        			if(addr==key%string2.size()||hash_table[addr]=="")
        			{
        				result.push_back(temp);
        				break;
        			}
        		}
        	}
    	}
    	delete [] hash_table;
        return result;
    }
};

class Solution {
public:
    /*
     * @param : a given string
     * @param : another given string
     * @return: An array of missing string
     */
    vector<string> missingString(string str1, string str2) {
        // Write your code here
        vector<string> vec1;
        vector<string> vec2;
        vector<string> res;
        
        string buf;
        stringstream ss1(str1); //字符流
        while (ss1 >> buf) {
            vec1.push_back(buf);
        }
        
        stringstream ss2(str2);
        while (ss2 >> buf) {
            vec2.push_back(buf);
        }
        

        for (int i = 0; i < vec1.size(); i++) {
            vector<string>::iterator it;
            it = find(vec2.begin(), vec2.end(), vec1[i]);
            if (it == vec2.end()) {
                res.push_back(vec1[i]);
            }
        }
        return res;
    }
};