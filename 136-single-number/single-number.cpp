class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hm;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(hm.count(nums[i]) > 0) {
                hm[nums[i]] += 1;
            } else {
                hm[nums[i]] = 1;
            }
        }

        for (pair<int, int> it: hm) {
            //cout<<it.first<<endl;
            if(it.second == 1) {
                return it.first;
            }
        }

        return 0;

    }
};