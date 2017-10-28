class Solution {
public:
    /*
     * @param n: An integer
     * @return: true if this is a happy number or false
     */
	vector<unsigned int> SplitDigits(int n)
	{
		vector<unsigned int> digits;
		do
		{
			digits.push_back(n%10);
			n /= 10;
		}while(n!=0);
		return digits;
	}
    bool isHappy(int n) {
        map<unsigned int,unsigned int> hash_table;
        vector<unsigned int> digits;
        while(hash_table.find(1)==hash_table.end())
        {
        	int temp = 0;
        	digits = SplitDigits(n);
        	for(auto it : digits)
        		temp += (int)pow(it,2);
        	pair<map<unsigned int,unsigned int>::iterator,bool> ret;
        	ret = hash_table.insert(pair<unsigned int, unsigned int> (n,temp));
        	if(!ret.second&&n!=1)
        		return false;
        	n = temp; 
        }
        return true;
    }
};