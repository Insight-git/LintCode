class Solution {
public:
    /*
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        map<int,unsigned int> hash_table;
        unsigned int i = 0;
        for(i=0;i<numbers.size();i++)
        	hash_table[numbers[i]] = i;
        for(i=0;i<numbers.size();i++)
        {
        	int temp = target - numbers[i];
        	if(hash_table.find(temp)!=hash_table.end()&&hash_table[temp]!=i)
        	{
        		result.push_back(i+1);
        		result.push_back(hash_table[temp]+1);
        		return result;
        	}
        }
        return result;
    }
};