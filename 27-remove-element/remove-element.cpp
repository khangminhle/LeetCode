class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> removedArr = {};

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == val) {
                continue;
            }
            removedArr.push_back(nums[i]);
        }

        nums = removedArr;

        return removedArr.size();  
        }
};