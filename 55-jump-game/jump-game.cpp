class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n-1;
        int i = goal-1;
        while(i >= 0) {
            if(i + nums[i] >= goal) {
                goal = i;
            } else {
                int j = i-1;
                if(j < 0) {return false;}
                bool flag = false;
                while(j >= 0) {
                    if(j + nums[j] >= goal) {
                        flag = true;
                        break;
                    }
                    j--;
                }

                if(flag == false) {
                    return false;
                }

            }
            i--;
        }
        return true;
    }
};