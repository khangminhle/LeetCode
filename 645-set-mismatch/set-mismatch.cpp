class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n+1, 0);

        for(int i = 0; i < n; i++) {
            hash[nums[i]] += 1;
        }

        int duplicate = -1;
        int errorNumber = -1;

        for(int i = 1; i <= n+1; i++) {
            if(hash[i] == 2) {
                duplicate = i;
            } else {
                if(hash[i] == 0) {
                    errorNumber = i;
                }
            }

            if(duplicate != -1 && errorNumber != -1) {
                break;
            }
        }

        return {duplicate, errorNumber};
    }
};