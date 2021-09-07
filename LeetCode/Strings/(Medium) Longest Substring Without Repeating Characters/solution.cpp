class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Faster solution using sliding window
        // space complexity O(m), time complexity O(n)
        int right = 0;
        int left = 0;
        int length = 0;
        vector<int> table (128, -1); // becasuse ASCII has 128 chars
        
        while(right < s.length()){
            char r = s[right];
            int idx = table[r];
            
            if(idx != -1 && idx >= left && idx < right){
                left = idx + 1;
            }
            
            length = max (length, right - left + 1);
            // save the index of that letter
            table[r] = right;
            right++;
        }
        return length;
        /*
        My solution = slow
        int length = 0;
        int count = 1;
        for(int i = 0; i < s.length(); i++){
            set<char> table;
            table.insert(s[i]);
            for(int j = i + 1; j < s.length(); j++){
                if(table.find(s[j]) == table.end()){
                    count++;
                    table.insert(s[j]);
                }
                else{
                    break;
                }
            }
            length = max(length, count);
            table.clear();
            count = 1;
        }
        return length;*/      
    }
};