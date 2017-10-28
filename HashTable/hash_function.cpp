class Solution {
public:
    /*
     * @param key: A string you should hash
     * @param HASH_SIZE: An integer
     * @return: An integer
     */
    int hashCode(string &key, int HASH_SIZE) {
        unsigned long long sum = 0;
        unsigned int i = 0;
        unsigned int length = key.size();
        if(length==0||HASH_SIZE==0)
            return 0;
        for(i=0;i<length;i++)
        {
            sum = sum * 33 + key[i];
            sum %= HASH_SIZE;
        }
        return sum;
    }
};