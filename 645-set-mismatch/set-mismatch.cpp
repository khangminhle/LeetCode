class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> unique;

        int sumOfCurrentNumbers = 0;
        int duplicate = 0;

        for(int i = 0; i < n; i++) {
            if(unique.count(nums[i]) > 0) {
                duplicate = nums[i];
            } else {
                unique.insert(nums[i]);
                sumOfCurrentNumbers += nums[i];
            }
        }

        if(duplicate == 0 ) {
            return {};
        }

        int errorNumber = (n*(n+1))/2 - sumOfCurrentNumbers;
        
        return {duplicate, errorNumber};

       
    }
};