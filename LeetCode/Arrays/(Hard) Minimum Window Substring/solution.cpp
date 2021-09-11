class Solution {
public:
    string minWindow(string s, string t) {   
        // My solution
        // Time complexity O(s + t)
        // Space complexity O(t)
        if(t.length() > s.length()) return "";
        
        // hashmap to store characters and their count in string t
        unordered_map<char, int> mp;
        for(int i = 0; i < t.length(); i++){
            mp[t[i]]++;
        }
        
        // variable count to store the total characters visited so far in string t
        int count = 0;
        
        // variables to traverse string s
        int left = 0;
        int right = 0;
        int min_left = 0;
        int min_right = 0;
        
        // variable to check minimum length
        int min_length = INT_MAX;
        
        while(right < s.size()){
            // check if new character
            if(mp.find(s[right]) != mp.end()){
                mp[s[right]]--;
                if(mp[s[right]] >= 0) count++;
            }            
            // if count is reached then traverse the left pointer to get minimum window
            while(count ==  t.size() && left <= right)
            {
                if(mp.find(s[left]) != mp.end()){
                    mp[s[left]]++;
                    if(mp[s[left]] > 0) count--;   
                }
                if(min_length > (right - left + 1))
                {
                    min_length = right - left + 1;
                    min_left = left;
                    min_right = right;
                }
                
                left++;
            }
            right++;
        }          
        return min_length == INT_MAX ? "" : string(s.begin() + min_left, s.begin() + min_right + 1);        
    }
};