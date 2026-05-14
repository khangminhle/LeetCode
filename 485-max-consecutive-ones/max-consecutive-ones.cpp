class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int countNumber = 0;
        int maxCount = 0;

        int n  = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                if(countNumber > maxCount) {
                    maxCount = countNumber;
                }
                countNumber = 0;
            } else {
                countNumber += 1;
            }
        }

        if(countNumber > maxCount) {
            return countNumber;
        }

        return maxCount;
    }
};