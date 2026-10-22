class Solution {
public:
    int maxArea(vector<int>& heights) {
      int ans = 0;
      int left = 0;
      int right = heights.size()-1;
      while(left<right){
        int high = min(heights[left], heights[right]);
        int dist = right-left;
        int area = high*dist;
        ans = max(ans, area);

        if(heights[left]<heights[right]) left++;
        else right--;
      }  
      return ans;
    }
};
