class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> hash;
        vector<int> result;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            if(hash.count(nums[i]) > 0) {
                continue;
            }

            int count = 0;
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    if(nums[i] > nums[j]) {
                        count += 1;
                    }
                }
            }
            hash[nums[i]] = count;
        }

        for(int i = 0; i < n; i++) {
            result.push_back(hash[nums[i]]);
        }

        return result;
    }
};