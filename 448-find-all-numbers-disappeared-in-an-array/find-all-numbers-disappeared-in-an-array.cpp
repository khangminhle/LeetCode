class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>hash(n+1, 0);
        vector<int>result;

        for(int i = 0; i < n; i++) {
            hash[nums[i]] += 1;
        }

        for(int i = 1; i <= n; i++) {
            if(hash[i] == 0) {
                result.push_back(i);
            }
        }

        return result;
    }
};