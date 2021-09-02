class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		// My solution which is fast (4 ms)
        vector<int> result;
        unordered_map <int, int> table;
        if(nums1.size() <= nums2.size())
        {
            for(int i = 0; i < nums1.size(); i++)
            {
                table[nums1[i]]++;
            }
            for(int i = 0; i < nums2.size(); i++){
                if(table.find(nums2[i]) != table.end() && table.at(nums2[i]) != 0)
                {
                    result.push_back(nums2[i]);
                    table[nums2[i]]--;
                }
            }
        }
        else{
            for(int i = 0; i < nums2.size(); i++)
            {
                table[nums2[i]]++;
            }
            for(int i = 0; i < nums1.size(); i++){
                if(table.find(nums1[i]) != table.end() && table.at(nums1[i]) != 0)
                {
                    result.push_back(nums1[i]);
                    table[nums1[i]]--;
                }
            }
        }
        return result;
		
		/*
		Another fast solution 
		sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>res;
        int i = 0,j=0;
        while(i<nums1.size() and j<nums2.size()){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
		*/
    }
};