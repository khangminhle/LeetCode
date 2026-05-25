class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max = 0;
        
        int left = 0;
        int right = left+1;

        while(right <= n-1) {
            if(prices[right] > prices[left]) {
                max += prices[right] - prices[left];
                left += 1;
                right += 1;
            } else {
                if(prices[right] < prices[left]) {
                    left = right;
                    right = left+1;
                } else {
                    left = right;
                    right = left+1;
                }
            }
        }

        return max;
    }
};