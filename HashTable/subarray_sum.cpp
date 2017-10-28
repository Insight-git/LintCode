class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        map<int,unsigned int> hash_table;
        unsigned int i = 0;
        int sum = 0;
        hash_table[0] = -1;
        for(i=0;i<nums.size();i++)
        {
        	sum += nums[i];
        	if(hash_table.find(sum)!=hash_table.end())
        	{
        		vector<int> result;
        		result.push_back(hash_table[sum]+1);
        		result.push_back(i);
        		return result;
        	}
        	hash_table[sum] = i;
        }
        vector<int> result;
        return result;
    }
};