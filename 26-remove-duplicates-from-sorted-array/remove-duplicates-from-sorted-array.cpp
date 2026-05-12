class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> duplicates = {};
        unordered_map<int,int> duplicate_map;
        for(int i = 0; i < nums.size(); i++) {
            if(duplicate_map.count(nums[i]) < 1) {
                duplicates.push_back(nums[i]);
                duplicate_map[nums[i]] = 0;
            }
        }

        nums = duplicates;

        return duplicates.size();
    }
};