class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while(left < right){   
            area = max(area, min(height[left], height[right])*abs(left - right));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return area;
    }
};