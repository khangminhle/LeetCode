class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
    
        int maxJump = 0;
        int goal = n-1;

        for(int i = 0; i < n; i++) {

            if(maxJump < i) {
                return false;
            }

            int ableToJump = i + nums[i];
            
            if(maxJump < ableToJump) {
                maxJump = ableToJump;
            }

            if(maxJump >= n-1) {
                return true;
            }
        }

        return true;
    }
};