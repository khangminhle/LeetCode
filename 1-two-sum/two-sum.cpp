class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;

        for(int i = 0; i < nums.size(); i++) {
            int numberToFind = target - nums[i];

            if(num_map.count(numberToFind)) {
                return {num_map[numberToFind], i};
            }

            num_map[nums[i]] = i;
        }

        return {};
    }
};