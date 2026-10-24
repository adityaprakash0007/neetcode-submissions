class Solution {
public:
    int characterReplacement(string s, int k) {
       unordered_map<char, int> mp;
       int freq = 0;
       int left = 0;
       int ans = 0;
       for(int right = 0; right<s.size(); right++){
        mp[s[right]]++;
        freq = max(freq, mp[s[right]]);
        while((right-left+1)-freq >k){
            mp[s[left]]--;
            left++;
        }
        ans = max(ans, right-left+1);
       } 
       return ans;
    }
};
