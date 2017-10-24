class Solution {
public:
    
    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        map<int,unsigned int> m;
        unsigned int i = 0;
        vector<int> result;
        for(i=0;i<nums1.size();i++)
        {
        	m[nums1[i]]++;
        }
        for(i=0;i<nums2.size();i++)
        {
        	if(m.find(nums2[i])!=m.end())
        	{
        		result.push_back(nums2[i]);
        		m[nums2[i]]--;
        		if(m[nums2[i]]==0)
        			m.erase(nums2[i]);
        	}
        }
        return result;
    }
};