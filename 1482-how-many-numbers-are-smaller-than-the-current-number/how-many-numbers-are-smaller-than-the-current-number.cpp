class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> frequency(101, 0);
        vector<int> result;

        for(int i = 0; i < n; i++) {
            frequency[nums[i]] += 1;
        }

        for(int i = 1; i < 101; i++) {
            frequency[i] += frequency[i-1];
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                result.push_back(0);
                continue;
            }
            result.push_back(frequency[nums[i]-1]);
        }

        return result;
    }
};