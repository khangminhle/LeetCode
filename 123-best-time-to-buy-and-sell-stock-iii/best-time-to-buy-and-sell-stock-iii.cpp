class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        left[0] = 0;
        right[n-1] = 0;

        int max = 0;
        int min_day = prices[0];

        for(int i = 1; i < n; i++) {
            if(prices[i] > min_day) {
                if((prices[i] - min_day) > max) {
                    max = prices[i] - min_day;
                }
            } else {
                min_day = prices[i];
            }
            left[i] = max;
        }

        max = 0;
        max = 0;
        int max_day = prices[n-1];

        for(int i = n-2; i >= 0; i--) {
            if(prices[i] > max_day) {
                max_day = prices[i];
            } else {
                int profit = max_day - prices[i];

                if(profit > max) {
                    max = profit;
                }
            }

            right[i] = max;
        }

        max = 0;
        for(int i = 0; i < n; i++) {
            if((left[i] + right[i]) > max) {
                max = left[i] + right[i];
            }
        }


        return max;
    }
};