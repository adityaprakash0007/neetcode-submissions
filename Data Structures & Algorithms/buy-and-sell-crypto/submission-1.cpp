class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int left = 0;
       int ans = 0;
       for(int i=1; i<prices.size(); i++){
         ans = max(ans, prices[i]-prices[left]);
           if (prices[i] < prices[left]) {
                left = i;
            }
       } 
       return ans;
    }
};
